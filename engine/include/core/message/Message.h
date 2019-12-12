// Message.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/message/IMessageHandler.h"

enum class MessageType{
	MSG_UNKOWN = 0,
	MSG_KEY_UP,
	MSG_KEY_DOWN,
	MSG_MOUSE_MOVED,
	MSG_COLLISION,
	MSG_OBJECT_DESTROYED
	// ...
};

enum class Bubble{
	BUBBLE_NOPE = 0,
	BUBBLE_CHILDREN,
	BUBBLE_PARENT
};

class Message {
public:
	explicit Message(MessageType type, Bubble bubble = Bubble::BUBBLE_NOPE);
	virtual ~Message();

	MessageType m_type; // needed: implies "smaller" scale of an Object: so derived class KeyMessage has MessageType KeyDown, which helps reaction to the message
	Bubble m_bubble;
	
	virtual void Send(IMessageHandler& handler) const;
	
protected:
	virtual void Dispatch(IMessageHandler& handler) const;	
};