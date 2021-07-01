#include "../include/chunkManager.h"

ChunkManager::ChunkManager()
{
	
	
		chunkRenderList.push_back(new Chunk(0, 0));
		chunkRenderList.push_back(new Chunk(0,16));
		chunkRenderList.push_back(new Chunk(16,16));
		chunkRenderList.push_back(new Chunk(16,0));
		chunkRenderList.push_back(new Chunk(16,-16)); 
		chunkRenderList.push_back(new Chunk(0,-16));
		chunkRenderList.push_back(new Chunk(-16,-16));
		chunkRenderList.push_back(new Chunk(-16,0));
		chunkRenderList.push_back(new Chunk(-16, 16));
	
}

void ChunkManager::renderChunks()
{
	//chunkRenderList.at(0)->bindShaderProgram(chunkRenderList.at(0)->shaderProgram);
	
	for (auto &ch : chunkRenderList)
	{
		ch->draw(ch->VAO);
	}
	
}
void ChunkManager::loadChunks(int& x, int& z)
{
	chunkRenderList.push_back(new Chunk(x, z));
	chunkRenderList.push_back(new Chunk(x, z+16));
	chunkRenderList.push_back(new Chunk(x+16, z+16));
	chunkRenderList.push_back(new Chunk(x+16, z));
	chunkRenderList.push_back(new Chunk(x+16, z-16));
	chunkRenderList.push_back(new Chunk(x, z-16));
	chunkRenderList.push_back(new Chunk(x-16, z-16));
	chunkRenderList.push_back(new Chunk(x-16, z));
	chunkRenderList.push_back(new Chunk(x-16, z+16));

}

ChunkManager::~ChunkManager()
{
	while (!chunkRenderList.empty())
	{
		delete chunkRenderList.back();
		chunkRenderList.pop_back();
	}
}