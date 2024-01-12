#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"


GameObject::GameObject(const char* texturesheet, int objx, int objy) 
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = objx;
	ypos = objy;
}

void GameObject::Update()
{
	srcRect.w = 128;
	srcRect.h = 128;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}