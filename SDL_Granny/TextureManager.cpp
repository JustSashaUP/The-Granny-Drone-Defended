#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

SDL_Texture* TextureManager::LoadTextTexture(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize)
{
	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
	SDL_Surface* surf = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surf);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return tex;
}

