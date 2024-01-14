#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static SDL_Texture* LoadTextTexture(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif
