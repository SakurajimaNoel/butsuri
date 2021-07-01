#pragma once

#include "baseDrawable.h"

#include <FastNoise/FastNoise.h>

#define CHUNKX 16
#define CHUNKY 16
#define CHUNKZ 16

class Chunk : public BaseDrawable
{
private:

    struct Vertex
    {
        GLint x,y,z;
        GLint tX, tY;
    };

    std::vector<Vertex> vertices;

   // static std::vector<Vertex> backFace;
    const static std::array<GLint, 30> backFace;
    const static std::array<GLint, 30> frontFace;
    const static std::array<GLint, 30> leftFace;
    const static std::array<GLint, 30> rightFace;
    const static std::array<GLint, 30> bottomFace;
    const static std::array<GLint, 30> topFace;



    GLuint VBO;
    const std::string vsPath = "../../../shaders/vertexShader.vert";
    const std::string fsPath = "../../../shaders/fragmentShader.frag";
    const std::string textureFaces = "../../../textures/smooth_stone.png";

public:
    Chunk(GLint translateX, GLint translateZ);
    ~Chunk();
    Chunk(const Chunk &) = delete;
    Chunk &operator = (const Chunk&) = delete;
    GLuint VAO, shaderProgram;
};
