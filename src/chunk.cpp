
#include "../include/chunk.h"


Chunk::Chunk(GLint translateX, GLint translateZ)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    bool isBlockEmpty[CHUNKX][CHUNKZ][32];
    
    //vertices.reserve(148000);

    //std::vector<float> noiseOutput(16 * 16 * 16);
    //FastNoise::SmartNode<> fnGenerator = FastNoise::NewFromEncodedNodeTree("EQACAAAAAAAgQBAAAAAAQBkAEwDD9Sg/DQAEAAAAAAAgQAkAAGZmJj8AAAAAPwEEAAAAAAAAAEBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAM3MTD4AMzMzPwAAAAA/");
    //fnGenerator->GenUniformGrid3D(noiseOutput.data(), translateX, 0, translateZ, 16, 16, 16, 0.2f, 1337);
  
    int index = 0;

    //chunk generation
    for (GLint x = 0; x< CHUNKX; ++x)
    {
        for (GLint z = 0; z < CHUNKZ ; ++z)
        {
            //int height = glm::perlin(glm::vec2((x + translateX) / 16.0f, (z + translateZ) / 16.0f)) * 10;

            for (GLint y = -CHUNKY; y < CHUNKY; ++y)
            {
                if (y == -CHUNKY) isBlockEmpty[x][z][y + 16] = false;
                else if ((glm::perlin(glm::vec3((x + translateX) / 16.0f, (z + translateZ) / 16.0f, y / 16.0f)) * 10) > 0) isBlockEmpty[x][z][y + 16] = false;
                else isBlockEmpty[x][z][y + 16] = true;
            }
        }
    }
   
    //mesh generation

    for(GLint x = 0; x < CHUNKX; ++x)
    {
        for (GLint z = 0; z < CHUNKZ; ++z)
        {
           
            //int height = glm::perlin(glm::vec2((x + translateX) / 16.0f, (z + translateZ) / 16.0f)) * 10;
            
            for (GLint y = -CHUNKY; y < CHUNKY; ++y)
            {

                if (isBlockEmpty[x][z][y+16]) continue;
                    
                if (y + 1 == CHUNKY || isBlockEmpty[x][z][y+17]) 
                {
                    for (float i = 0; i < 6; i++)
                    {
                        vertices.push_back({ topFace[i * 5] + x + translateX, topFace[1 + i * 5] + y  , topFace[2 + i * 5] + z + translateZ, topFace[3 + i * 5], topFace[4 + i * 5] });
                    }
                }
                if (y != -CHUNKY)
                {
                    if (isBlockEmpty[x][z][y + 15])
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            vertices.push_back({ bottomFace[i * 5] + x + translateX, bottomFace[1 + i * 5] + y , bottomFace[2 + i * 5] + z + translateZ, bottomFace[3 + i * 5], bottomFace[4 + i * 5] });
                        }
                    }

                    if (x + 1 == CHUNKX || isBlockEmpty[x + 1][z][y + 16])
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            vertices.push_back({ rightFace[i * 5] + x + translateX , rightFace[1 + i * 5] + y , rightFace[2 + i * 5] + z + translateZ , rightFace[3 + i * 5], rightFace[4 + i * 5] });
                        }
                    }

                    if (x == 0 || isBlockEmpty[x - 1][z][y + 16])
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            vertices.push_back({ leftFace[i * 5] + x + translateX, leftFace[1 + i * 5] + y , leftFace[2 + i * 5] + z + translateZ , leftFace[3 + i * 5], leftFace[4 + i * 5] });
                        }
                    }

                    if (z + 1 == CHUNKZ || isBlockEmpty[x][z + 1][y + 16])
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            vertices.push_back({ frontFace[i * 5] + x + translateX , frontFace[1 + i * 5] + y , frontFace[2 + i * 5] + z + translateZ, frontFace[3 + i * 5], frontFace[4 + i * 5] });
                        }
                    }

                    if (z == 0 || isBlockEmpty[x][z - 1][y + 16])
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            vertices.push_back({ backFace[i * 5] + x + translateX , backFace[1 + i * 5] + y , backFace[2 + i * 5] + z + translateZ, backFace[3 + i * 5], backFace[4 + i * 5] });
                        }
                    }
                }
                

            }
        }
    }


    bindVertexBuffer(vertices, VAO, VBO);
    setShaders(vsPath, fsPath, shaderProgram);
    setTexture(textureFaces);
    
}

Chunk::~Chunk()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
}
const std::array<GLint, 30> Chunk::backFace = {
        0, 0, 0, 0, 0,
        1, 0, 0, 1, 0,
        1, 1, 0, 1, 1,
        1, 1, 0, 1, 1,
        0, 1, 0, 0, 1,
        0, 0, 0, 0, 0
};

const std::array<GLint, 30> Chunk::frontFace = {
        0, 0, 1, 0, 0,
        1, 0, 1, 1, 0,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        0, 1, 1, 0, 1,
        0, 0, 1, 0, 0
};

const std::array<GLint, 30> Chunk::leftFace =  {
        0, 1, 1, 0, 1,
        0, 1, 0, 1, 1,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 1
};

const std::array<GLint, 30> Chunk::rightFace = {
        1, 1, 1, 0, 1,
        1, 1, 0, 1, 1,
        1, 0, 0, 1, 0,
        1, 0, 0, 1, 0,
        1, 0, 1, 0, 0,
        1, 1, 1, 0, 1
};

const std::array<GLint, 30> Chunk::bottomFace = {
        0, 0, 0, 0, 1,
        1, 0, 0, 1, 1,
        1, 0, 1, 1, 0,
        1, 0, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 1
};

const std::array<GLint, 30> Chunk::topFace = {
        0, 1, 0, 0, 1,
        1, 1, 0, 1, 1,
        1, 1, 1, 1, 0,
        1, 1, 1, 1, 0,
        0, 1, 1, 0, 0,
        0, 1, 0, 0, 1
};
