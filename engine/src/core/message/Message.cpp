//Message.cpp
#include "core/message/Message.h"

Message::Message(MessageType type, Bubble bubble)
: m_type(type), m_bubble(bubble) {}

Message::~Message() {}

void Message::Send(IMessageHandler& handler) const {
	Dispatch(handler);

	if(m_bubble == Bubble::BUBBLE_NOPE) return;

	// Bubble up
	if(m_bubble == Bubble::BUBBLE_PARENT && handler.GetParent() != nullptr){
		Dispatch(*handler.GetParent()); //getParent returns pointer!!!
	}

	// Bubble down
	if(m_bubble == Bubble::BUBBLE_CHILDREN){
		handler.SendToChildren(*this);
	}
}

void Message::Dispatch(IMessageHandler& handler) const{
	handler.HandleMessage(*this);
}