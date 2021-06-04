#include "../include/baseDrawable.h"

void BaseDrawable::setShaders(const std::string &vsPath, const std::string &fsPath, GLuint &shaderProgram)
{
    //vertex shader
    std::string vertexShaderSource;
    std::ifstream vsFile(vsPath, std::ios::in);
    if(vsFile.is_open())
    {
        std::stringstream stringStream;
        stringStream << vsFile.rdbuf();
        vertexShaderSource = stringStream.str();
        vsFile.close();
    }
    const GLchar *vertexShaderCode = vertexShaderSource.c_str();
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertexShader);

    BaseDrawable::shaderCheck(vertexShader);

    //fragment shader
    std::string fragmentShaderSource;
    std::ifstream fsFile(fsPath, std::ios::in);
    if(fsFile.is_open())
    {
        std::stringstream stringStream;
        stringStream << fsFile.rdbuf();
        fragmentShaderSource = stringStream.str();
        fsFile.close();
    }

    const GLchar *fragmentShaderCode = fragmentShaderSource.c_str();
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragmentShader);

    BaseDrawable::shaderCheck(fragmentShader);

    //shader program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    BaseDrawable::shaderProgramCheck(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void BaseDrawable::shaderCheck(GLuint &shader)
{
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout<<"ERROR::SHADER_COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }
    success = GL_FALSE;
}

void BaseDrawable::shaderProgramCheck(GLuint &shaderProgram)
{
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
    }
    success = GL_FALSE;
}


void BaseDrawable::bindShaderProgram(GLuint &shaderProgram)
{
    glUseProgram(shaderProgram);
}

void BaseDrawable::setTexture(std::string &texturePath)
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    GLint width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    GLubyte *data = stbi_load("../textures/grass_side.png", &width, &height, &channels, 3);
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout<<"ERROR::TEXTURE_LOADING_FAILED\n";
    }
    stbi_image_free(data);
}



void BaseDrawable::draw(GLuint &VAO)
{
    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, nullptr);
}
