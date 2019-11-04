//RenderModule.cpp
#include "core/RenderModule.h"

RenderModule::RenderModule() :
timePerFrame(sf::seconds(1.0f / 60.0f)) {}

RenderModule::~RenderModule() {}

void RenderModule::StartUp(){
	Locator::getConsole()->print("Startup", "RenderModule");

	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Modest-Engine");
}

void RenderModule::ShutDown(){
	Locator::getConsole()->print("Shutdown", "RenderModule");
	
	if(window->isOpen()){
		window->close();
	}
}

void RenderModule::Draw(){
	window->clear();

	for(size_t i = drawables.size() - 1, iLen = 0; i >= iLen; i--){
		window->draw(*drawables[i]);
	}

	window->display();
}

void RenderModule::AddDrawable(sf::Drawable* drawable){
	drawables.push_back(drawable);
}

bool RenderModule::RemoveDrawable(sf::Drawable* drawable){
	const auto removedComponent = std::find(
			drawables.begin(), 
			drawables.end(), 
			drawable
		);
		
		const bool isFound = removedComponent != drawables.end();
		if(isFound){
			drawables.erase(removedComponent);
		}

		return isFound;
}

const std::vector<sf::Drawable*> RenderModule::GetDrawables() const{
	return drawables;
}
	
const bool RenderModule::WindowsIsOpen() const{
	return window->isOpen();
}
