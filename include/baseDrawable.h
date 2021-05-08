#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class BaseDrawable
{
protected:
    void setShaders(const std::string &vsPath, const std::string &fsPath, GLuint &shaderProgram);

    template<class T>
    //weird linker error if defined in .cpp
    void bindVertexBuffer(const std::vector<T> &vertices, const std::vector<GLuint> &indices, GLuint &VAO, GLuint &VBO,
                          GLuint &EBO)
    {
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(T), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

private:
    GLint success;
    GLchar infoLog[512];

    void shaderCheck(GLuint &shader);

    void shaderProgramCheck(GLuint &shaderProgram);

public:
    void bindShaderProgram(GLuint &shaderProgram);

    void draw(GLuint &VAO);

};
