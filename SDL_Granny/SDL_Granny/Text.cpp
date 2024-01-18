#include "Text.h"

Text::Text(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, int width, int height, int x, int y)
{
	Game* game;

	Text::LoadText(message, fontFile, color, fontSize);

	src.x = src.y = 0;
	src.w = dest.w = width;
	src.h = dest.h = height;

	dest.x = x;
	dest.y = y;
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}

void Text::LoadText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize)
{
	texture = TextureManager::LoadTextTexture(message, fontFile, color, fontSize);
}

void Text::DrawText()
{
	TextureManager::Draw(texture, src, dest);
}