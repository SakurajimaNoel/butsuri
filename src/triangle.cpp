#include "../include/triangle.h"

Triangle::Triangle()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    bindVertexBuffer(vertices, indices, VAO, VBO, EBO);
    setShaders(vsPath, fsPath, shaderProgram);

}

Triangle::~Triangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
}

