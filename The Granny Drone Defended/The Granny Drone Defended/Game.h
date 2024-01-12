#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>
class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool running() { return isRunning; }
	bool showMenu();
	void handleEvents();
	void render();
	void update();
	void jarUpdate();
	void enemiUpdate();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	// jar and enemi settings
	uint64_t currentTime = SDL_GetTicks();
	uint64_t spendJarTime = 0;
	uint64_t spendEnemiTime = 0;
	uint64_t enemiCounter = 0;
	uint64_t enemispeed = 1;
	uint64_t jarspeed = 5;
	uint64_t oneTime = 10;
	uint64_t over = 0;
	// score settings
	uint64_t scoreCounter = 0;
	uint64_t scoreEnemiSpeedLimit = 1000;
	uint64_t scoreJarSpeedLimit = 2000;
	uint64_t scoreW = 115, scoreH = 32;
	uint64_t scoreLimitSize = 1000;

	uint64_t liveCounter = 1;

	bool isMenu = true;
	bool isHarm = false;

private:
	int counter = 0;
	int totalcurrentTime = counter;
	bool isRunning;
	SDL_Window* window;
};

#endif