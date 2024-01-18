#ifndef ANIMATION_H
#define ANIMATION_H

struct Animation
{
	int index;
	int frames;
	int speed;

	Animation() {};
	Animation(int i, int fr, int sp)
	{
		index = i;
		frames = fr;
		speed = sp;
	}
};

#endif