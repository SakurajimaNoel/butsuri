#include "../include/window.h"
#include <fstream>
#include <sstream>

int main()
{
    Window window(800, 600);  //window creation


    //vertex shader
    std::string vertexShaderString;
    std::ifstream vsFile("../shaders/vertexShader.vert", std::ios::in);
    if (vsFile.is_open())
    {
        std::stringstream stringStream;
        stringStream << vsFile.rdbuf();
        vertexShaderString = stringStream.str();
        vsFile.close();

    }
    const GLchar *vertexShaderSource = vertexShaderString.c_str();
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //fragment shader / pixel shader
    std::string fragmentShaderString;
    std::ifstream fsFile("../shaders/fragmentShader.frag", std::ios::in);
    while (fsFile.is_open())
    {
        std::stringstream stringStream;
        stringStream << fsFile.rdbuf();
        fragmentShaderString = stringStream.str();
        fsFile.close();
    }
    const GLchar *fragmentShaderSource = fragmentShaderString.c_str();

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //shader program
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    success = 0;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //vertex buffer binding
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f, 0.5f, 0.0f
    };

    GLuint indices[] = {
        0, 1, 2
    };

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //input assembler / vertex attributes

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);  //unbind vbo
    glBindVertexArray(0);             //unbind vao
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //unbind eao
    //render loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        glClearColor(1.0f, 0.25f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    return 0;
}
