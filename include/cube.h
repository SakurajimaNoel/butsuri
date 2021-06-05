#pragma once

#include "baseDrawable.h"

class Cube : public BaseDrawable
{
private:
    struct Vertex
    {
        GLfloat x, y, z;
    };

    const std::vector<Vertex> vertices =
    {
            {-0.5f,-0.5f,-0.5f},
            {-0.5f,-0.5f, 0.5f},
            {-0.5f, 0.5f,-0.5f},
            {-0.5f, 0.5f, 0.5f},
            {0.5f,-0.5f,-0.5f},
            {0.5f,-0.5f, 0.5f},
            {0.5f, 0.5f,-0.5f},
            {0.5f, 0.5f, 0.5f}

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
    const std::string vsPath = "../shaders/cubeMap.vert";
    const std::string fsPath = "../shaders/cubeMap.frag";
    const std::vector<std::string> textureFaces =
            {
                    "../textures/grass_side.png",
                    "../textures/grass_side.png",
                    "../textures/grass_side.png",
                    "../textures/grass_side.png",
                    "../textures/grass_side.png",
                    "../textures/grass_side.png"
            };

public:

    Cube();
    ~Cube();
    Cube(const Cube &) = delete;
    Cube &operator=(const Cube&) = delete;
    GLuint VAO, shaderProgram;

};
