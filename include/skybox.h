#pragma once

#include "baseDrawable.h"

class Skybox : public BaseDrawable
{
private:
    struct Vertex
    {
        GLfloat x, y, z;
    };

    const std::vector<Vertex> vertices =
            {
                    {-1.0f,-1.0f,-1.0f},
                    {-1.0f,-1.0f, 1.0f},
                    {-1.0f, 1.0f,-1.0f},
                    {-1.0f, 1.0f, 1.0f},
                    {1.0f,-1.0f,-1.0f},
                    {1.0f,-1.0f, 1.0f},
                    {1.0f, 1.0f,-1.0f},
                    {1.0f, 1.0f, 1.0f}

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
    const std::string vsPath = "../shaders/skybox.vert";
    const std::string fsPath = "../shaders/skybox.frag";
    const std::vector<std::string> textureFaces =
            {
                    "../textures/right.jpg",
                    "../textures/left.jpg",
                    "../textures/top.jpg",
                    "../textures/bottom.jpg",
                    "../textures/front.jpg",
                    "../textures/back.jpg"
            };

public:

    Skybox();
    ~Skybox();
    Skybox(const Skybox &) = delete;
    Skybox &operator=(const Skybox&) = delete;
    GLuint VAO, shaderProgram;
};
