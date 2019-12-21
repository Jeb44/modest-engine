//System.cpp
#include "core/System.h"

void System::Init(){}

void System::Update(sf::Time deltaTime){}

IMessageHandler* System::GetParent() const{
	return nullptr;
}

void System::SendToChildren(const Message& msg){}