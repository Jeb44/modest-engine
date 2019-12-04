// Message.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/resource/Handle.h"

class Message {
public:
	explicit Message();
	virtual ~Message();

	Handle GetID();
	
private:
	Handle id; 
	/* some message file need to be created to "synchronise" id and enum?
	 * Function(Message* msg){
	 * 	switch(msg->GetID()){
	 *  	case ePlayerNearby:
	 * 			this->Glimmer((LocationMSG*)msg);
	 *			break;
	 * 		case eActivate:
	 * 			this->Open();
	 * 			break;
	 *		}
	 * }
	 * 
	 * struct LocationMSG{
	 * 		enum id;
	 * 		Vec2 position;
	 * }	
	 */
};