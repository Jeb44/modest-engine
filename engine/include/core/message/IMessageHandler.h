// IMessageHandler.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

class Message;
class KeyMessage;
class MouseMessage;

class IMessageHandler {
public:

	virtual void SetParent(IMessageHandler& parent);

	// Bubbling
	virtual IMessageHandler* GetParent() const = 0;
	// component -> return Entity
	// entity -> return space/gamefactorysystem or what every suits best

	virtual void SendToChildren(const Message& msg) = 0;
	// engine -> return systems
	// game object system -> return game objects
	// game object -> return components

	virtual void HandleMessage(const Message& msg);
	virtual void HandleMessage(const KeyMessage& msg);
	virtual void HandleMessage(const MouseMessage& msg);
	// ...

protected:
	IMessageHandler* m_parent;
};