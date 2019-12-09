//Message.cpp
#include "core/message/Message.h"

Message::Message(MessageType type, Bubble bubble)
: m_type(type), m_bubble(bubble) {}

Message::~Message() {}

void Message::Send(IMessageHandler& handler) const {
	Dispatch(handler);
	// Bubble up
	if(m_bubble == Bubble::BUBBLE_PARENT && handler.GetParent() != NULL){
		Dispatch(*handler.GetParent());
	}

	// Bubble down
	if(m_bubble == Bubble::BUBBLE_PARENT){
		handler.SendToChildren(*this);
	}
}