#include "../include/skybox.h"

Skybox::Skybox()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    bindVertexBuffer(vertices, indices, VAO, VBO, EBO);
    setShaders(vsPath, fsPath, shaderProgram);
    setTexture(textureFaces);
}

Skybox::~Skybox()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
}