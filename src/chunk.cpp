
#include "../include/chunk.h"


Chunk::Chunk()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    bool isBlock[CHUNKX][CHUNKY][CHUNKZ];
    vertices.reserve(148000);
    //chunk generation
    for(GLbyte x =0; x< CHUNKX; x++)
    {
        for (GLbyte y = 0; y < CHUNKY ; y++)
        {
            for (GLbyte z = 0; z < CHUNKZ; z++)
            {

                std::cout<<"Hel";

            }
        }
    }
    std::vector<float> noiseOutput(16 * 16 * 16);
    FastNoise::SmartNode<> fnGenerator = FastNoise::NewFromEncodedNodeTree("EQACAAAAAAAgQBAAAAAAQBkAEwDD9Sg/DQAEAAAAAAAgQAkAAGZmJj8AAAAAPwEEAAAAAAAAAEBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAM3MTD4AMzMzPwAAAAA/");
    fnGenerator->GenUniformGrid3D(noiseOutput.data(), 0, 0, 0, 16, 16, 16, 0.2f, 1337);
    //mesh generation
    int index =0;
    for(GLint x = 0; x < CHUNKX; x++)
    {
        for (GLint y = 0; y < CHUNKY; y++)
        {
            for (GLint z = 0; z < CHUNKZ; z++)
            {
                float height = glm::perlin(glm::vec2(x/16.f,z/16.f))*10;
                std::cout<<noiseOutput[index++];


                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({topFace[i*5] + x , topFace[1 + i*5] + y + (int)height , topFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});

                    }

                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({bottomFace[i*5] + x , bottomFace[1 + i*5] + y + (int)height , bottomFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }

                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({rightFace[i*5] + x , rightFace[1 + i*5] + y+ (int)height, rightFace[2 + i*5] + z + 1 , backFace[3 + i*5], backFace[4 + i*5]});
                    }

                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({leftFace[i*5] + x , leftFace[1 + i*5] + y+ (int)height, leftFace[2 + i*5] + z - 1 , backFace[3 + i*5], backFace[4 + i*5]});
                    }

                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({frontFace[i*5] + x + 1 , frontFace[1 + i*5] + y+ (int)height, frontFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }

                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({backFace[i*5] + x - 1 , backFace[1 + i*5] + y+ (int)height, backFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }


            }
        }
    }


    //mesh generation
    /*for(GLint x = 0; x < CHUNKX; x++)
    {
        for (GLint y = 0; y < CHUNKY; y++)
        {
            for (GLint z = 0; z < CHUNKZ; z++)
            {
                float height = glm::perlin(glm::vec2(x/16.f,z/16.f))*10;

                if(isBlock[x][y][z]==false)
                {
                    continue;
                }
                if (isBlock[x][y+1][z] == false && y+1 < CHUNKY)
                {
                    // add face top
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({topFace[i*5] + x , topFace[1 + i*5] + y + (int)height , topFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});

                    }
                }
                if (isBlock[x][y-1][z] == false && y - 1 > 0)
                {
                    // add face bottom
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({bottomFace[i*5] + x , bottomFace[1 + i*5] + y + (int)height , bottomFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }
                }
                if (isBlock[x+1][y][z] == false && x + 1 < CHUNKX)
                {//right
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({rightFace[i*5] + x , rightFace[1 + i*5] + y+ (int)height, rightFace[2 + i*5] + z + 1 , backFace[3 + i*5], backFace[4 + i*5]});
                    }
                }
                if (isBlock[x-1][y][z] == false && x - 1 > 0)
                {//left
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({leftFace[i*5] + x , leftFace[1 + i*5] + y+ (int)height, leftFace[2 + i*5] + z - 1 , backFace[3 + i*5], backFace[4 + i*5]});
                    }
                }
                if (isBlock[x][y][z+1] == false && z+1 < CHUNKZ)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({frontFace[i*5] + x + 1 , frontFace[1 + i*5] + y+ (int)height, frontFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }
                }
                if (isBlock[x][y][z-1] == false && z -1 > 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        vertices.push_back({backFace[i*5] + x - 1 , backFace[1 + i*5] + y+ (int)height, backFace[2 + i*5] + z, backFace[3 + i*5], backFace[4 + i*5]});
                    }
                }

            }
        }
    }*/

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
const std::array<int, 30> Chunk::backFace = {
        0, 0, 0, 0, 0,
        1, 0, 0, 1, 0,
        1, 1, 0, 1, 1,
        1, 1, 0, 1, 1,
        0, 1, 0, 0, 1,
        0, 0, 0, 0, 0
};

const std::array<int, 30> Chunk::frontFace = {
        0, 0, 1, 0, 0,
        1, 0, 1, 1, 0,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        0, 1, 1, 0, 1,
        0, 0, 1, 0, 0
};

const std::array<int, 30> Chunk::leftFace =  {
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0,0,1,
        0, 0, 1,0,0,
        0, 1, 1,1,0
};

const std::array<int, 30> Chunk::rightFace = {
        1, 1, 1,1,0,
        1, 1, 0,1,1,
        1, 0, 0,0,1,
        1, 0, 0,0,1,
        1, 0, 1,0,0,
        1, 1, 1,1,0
};

const std::array<int, 30> Chunk::bottomFace = {
        0, 0, 0,0,1,
        1, 0, 0,1,1,
        1, 0, 1,1,0,
        1, 0, 1,1,0,
        0, 0, 1,0,0,
        0, 0, 0,0,1
};

const std::array<int, 30> Chunk::topFace = {
        0, 1, 0,0,0,
        1, 1, 0,1,0,
        1, 1, 1,1,0,
        1, 1, 1,1,1,
        0, 1, 1,0,1,
        0, 1, 0,0,0
};
