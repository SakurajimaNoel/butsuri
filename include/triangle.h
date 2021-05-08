#pragma once

#include "baseDrawable.h"

class Triangle : public BaseDrawable
{
private:
    struct Vertex
    {
        GLfloat x, y, z;
    };

    const std::vector<Vertex> vertices = {
            {-0.5f, -0.5f, 0.0f},
            {0.5f,  -0.5f, 0.0f},
            {0.0f,  0.5f,  0.0f}
    };

    const std::vector<GLuint> indices = {
            0, 1, 2
    };

    GLuint VBO, EBO;
    const std::string vsPath = "../shaders/vertexShader.vert";
    const std::string fsPath = "../shaders/fragmentShader.frag";

public:
    Triangle();

    ~Triangle();

    GLuint VAO, shaderProgram;

    Triangle(const Triangle &) = delete;

    Triangle &operator=(const Triangle &) = delete;


};