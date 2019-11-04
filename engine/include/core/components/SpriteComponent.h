// SpriteComponent.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/IEntityComponent.h"

#include "SFML/Graphics.hpp"

class SpriteComponent : IEntityComponent {
public:
	explicit SpriteComponent();
	virtual ~SpriteComponent();
	
	virtual void OnInit(Entity& go);
	virtual void OnStart(Entity& go);
	virtual void OnUpdate(Entity& go);
	virtual void OnFixedUpdate(Entity& go);
	virtual void OnEnd(Entity& go);

	virtual void SetTextureFilePath(std::string filePath);

private:
	sf::Sprite* sprPlayer;
	sf::Texture* texPlayer;
	std::string strTexturePath;
				
	// texPlayer = new sf::Texture();
	// if(!texPlayer->loadFromFile("../graphics/me_github_preview.png")){
	// 	// Handle loading error
	// }

	// sprPlayer = new sf::Sprite(*texPlayer);
	// sprPlayer->setPosition(100.0f, 100.0f);
};