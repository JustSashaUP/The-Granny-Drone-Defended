#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Entity* currentEntity;

	bool animated = false;

public:

	int animIndex = 0;
	int frames = 0;
	int speed = 100;
	int frameCounter = 0;
	const char* currentAnimation;

	std::map<const char*, Animation> animations;

	SpriteComponent() = default;
	SpriteComponent(const char* filePath)
	{
		SetTexture(filePath);
	}

	SpriteComponent(const char* filePath, bool isAnimated)
	{
		animated = isAnimated;

		Animation throwing = Animation(0, 8, 50);
		Animation climb = Animation(1, 2, 100);
		Animation idle = Animation(2, 2, 200);

		animations.emplace("throwing", throwing);
		animations.emplace("idle", idle);
		animations.emplace("climb", climb);

		Play("idle");
		texture = TextureManager::LoadTexture(filePath);
	}

	SpriteComponent(const char* filePath, bool isAnimated, int index)
	{
		if (index == 0)
		{
			animated = isAnimated;

			Animation rotating = Animation(0, 8, 200);

			animations.emplace("rotating", rotating);

			Play("rotating");
			texture = TextureManager::LoadTexture(filePath);
		}
		if (index == 1)
		{
			animated = isAnimated;

			Animation flying = Animation(0, 4, 100);
			Animation destroyed = Animation(1, 7, 50);

			animations.emplace("flying", flying);
			animations.emplace("destroyed", destroyed);

			Play("flying");
			texture = TextureManager::LoadTexture(filePath);
		}
		if (index == 2)
		{
			animated = isAnimated;

			Animation idle = Animation(1, 3, 200);
			Animation switching = Animation(0, 3, 100);

			animations.emplace("idle", idle);
			animations.emplace("switching", switching);

			Play("idle");
			texture = TextureManager::LoadTexture(filePath);
		}
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void SetTexture(const char* tex)
	{
		texture = TextureManager::LoadTexture(tex);
	}


	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{

		if (animated)
		{
			frameCounter++;
			if (frameCounter >= frames)
			{
				frameCounter = 0;
			}
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;

		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
		currentAnimation = animName;
	}
};

#endif