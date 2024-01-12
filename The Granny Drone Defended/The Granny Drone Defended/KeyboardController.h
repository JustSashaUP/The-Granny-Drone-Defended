#ifndef KEYBOARDCONTORLLER_H
#define KEYBOARDCONTROLLER_H

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	SpriteComponent* spriteJar;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -3;
				sprite->Play("climb");
				break;
			case SDLK_s:
				transform->velocity.y = 3;
				sprite->Play("climb");
				break;
			/*/case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;*/
			case SDLK_SPACE:
				sprite->Play("throwing");
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
			case SDLK_s:
				transform->velocity.y = 0;
				sprite->Play("idle");
				break;
			/*case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;*/
			case SDLK_SPACE:
				sprite->Play("idle");
				break;
			default:
				break;
			}
		}
	}

};
#endif KEYBOARDCONTROLLER_H