#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../include/stb_image.h"

class BaseDrawable
{
protected:
    void setShaders(const std::string &vsPath, const std::string &fsPath, GLuint &shaderProgram);
    void setTexture(std::string &texturePath);

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
        indexSize = indices.size();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *) nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*) (3* sizeof (GLfloat)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

private:
    GLint success;
    GLchar infoLog[512];
    GLuint texture, indexSize;
    void shaderCheck(GLuint &shader);

    void shaderProgramCheck(GLuint &shaderProgram);

public:
    void bindShaderProgram(GLuint &shaderProgram);

    void draw(GLuint &VAO);

};
