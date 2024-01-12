#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, int objx, int objy);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

#endif