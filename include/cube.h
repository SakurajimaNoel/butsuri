#pragma once

#include "baseDrawable.h"

class Cube : public BaseDrawable
{
private:
    struct Vertex
    {
        GLfloat x, y, z;
        GLfloat tX, tY;
    };

    const std::vector<Vertex> vertices =
    {
            {-0.5f,-0.5f,-0.5f, 1.0f, 0.0f},
            {-0.5f,-0.5f, 0.5f, 0.0f, 0.0f},
            {-0.5f, 0.5f,-0.5f, 1.0f, 1.0f},
            {-0.5f, 0.5f, 0.5f, 0.0f, 1.0f},
            {0.5f,-0.5f,-0.5f, 1.0f, 0.0f},
            {0.5f,-0.5f, 0.5f, 0.0f, 0.0f},
            {0.5f, 0.5f,-0.5f, 1.0f, 1.0f},
            {0.5f, 0.5f, 0.5f, 0.0f, 1.0f}

    };

    const std::vector<GLuint> indices =
    {
            0,2,1,	2,3,1,
            1,3,5, 	3,7,5,
            2,6,3, 	3,6,7,
            4,5,7, 	4,7,6,
            0,4,2, 	2,4,6,
            0,1,4, 	1,5,4
    };

    GLuint VBO,EBO;
    const std::string vsPath = "../shaders/vertexShader.vert";
    const std::string fsPath = "../shaders/fragmentShader.frag";
    std::string texturePath = "../textures/grass_side.png";

public:

    Cube();
    ~Cube();
    Cube(const Cube &) = delete;
    Cube &operator=(const Cube&) = delete;
    GLuint VAO, shaderProgram;

};
