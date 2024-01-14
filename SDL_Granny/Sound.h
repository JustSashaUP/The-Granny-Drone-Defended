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

	static Mix_Music* PlayMusic(const char* namePath)
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		Mix_Music* music = LoadMusic(namePath);
		return music;
	}

};

#endif