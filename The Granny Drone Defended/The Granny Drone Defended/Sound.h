#ifndef SOUND_H
#define SOUND_H

#include "SDL_mixer.h"

struct Sound
{
	static Mix_Music* LoadMusic(const char * namePath) {
		Mix_Music* music = Mix_LoadMUS(namePath);
		return music;
	}

	static Mix_Chunk* LoadSound(const char* namePath)
	{
		Mix_Chunk* chunk = Mix_LoadWAV(namePath);
		return chunk;
	}
};

#endif