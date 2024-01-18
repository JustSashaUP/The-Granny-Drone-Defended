#ifndef MAP_H
#define MAP_H

#include "Game.h"

class Map
{
public:
	Map(const char* fileName);
	~Map();

	void LoadMap(const char* fileName);
	void DrawMap();
private:
	SDL_Rect src, dest;

	SDL_Texture* garden_mp;
};

#endif
