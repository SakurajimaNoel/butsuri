#pragma once

#include "chunk.h"

class ChunkManager : public BaseDrawable
{

private:
	

public:
	std::vector<Chunk*> chunkRenderList;
	ChunkManager();
	~ChunkManager();
	ChunkManager(const ChunkManager &) = delete;
	ChunkManager& operator=(const ChunkManager &) = delete;
	void renderChunks();
	void loadChunks(int& x, int& z);
	
};