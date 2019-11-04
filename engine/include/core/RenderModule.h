// RenderModule.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "SFML/Graphics.hpp"
#include "common/Locator.h"

#include <vector>

class RenderModule {
public:
	explicit RenderModule();
	virtual ~RenderModule();
	
	void StartUp();
	void ShutDown();

	void Draw(); // ?

	void AddDrawable(sf::Drawable* drawable);
	bool RemoveDrawable(sf::Drawable* drawable);
	const std::vector<sf::Drawable*> GetDrawables() const;

	const bool WindowsIsOpen() const;
	
private:
	const sf::Time timePerFrame;
	sf::Time deltaTime = sf::Time::Zero;

	sf::RenderWindow* window;
	std::vector<sf::Drawable*> drawables;
};