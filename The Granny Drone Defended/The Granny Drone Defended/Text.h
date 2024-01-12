#ifndef TEXT_H
#define TEXT_H

#include "SDL.h"
#include "TextureManager.h"

class Text
{
public:
	Text(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, int width, int height, int x, int y);
	~Text();

	void LoadText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize);
	void DrawText();
private:
	SDL_Rect src, dest;
	SDL_Texture* texture;
};

#endif