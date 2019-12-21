//IMessageHandler.cpp
#include "core/message/IMessageHandler.h"

void IMessageHandler::SetParent(IMessageHandler& parent){
	m_parent = &parent;
}

void IMessageHandler::HandleMessage(const Message& msg){}
void IMessageHandler::HandleMessage(const KeyMessage& msg){}
void IMessageHandler::HandleMessage(const MouseMessage& msg){}
// ...