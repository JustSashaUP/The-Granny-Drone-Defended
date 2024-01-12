#include "Map.h"
#include "Game.h"
#include "TextureManager.h"

Map::Map(const char* fileName)
{

	Game* game;

	Map::LoadMap(fileName);

	src.x = src.y = 0;
	src.w = dest.w = 1600;
	src.h = dest.h = 800;

	dest.x = dest.y = 0;
}

Map::~Map()
{
	SDL_DestroyTexture(garden_mp);
}


void Map::LoadMap(const char* fileName)
{
	garden_mp = TextureManager::LoadTexture(fileName);
}

void Map::DrawMap()
{
	TextureManager::Draw(garden_mp, src, dest);
}
