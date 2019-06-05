//Transform.cpp
#include "core/Transform.h"


namespace ME{
	Transform::Transform() {}
	Transform::~Transform() {}


	void Transform::setPosition(MM::Vector3 newPosition){
		position = newPosition;
	}

	void Transform::setRotation(MM::Vector3 newRotation){
		rotation = newRotation;
	}

	void Transform::setScale(MM::Vector3 newScale){
		scale = newScale;
	}

	MM::Vector3* Transform::getPosition(){
		return &position;
	}
	MM::Vector3* Transform::getRotation(){
		return &rotation;
	}
	MM::Vector3* Transform::getScale(){
		return &scale;
	}
}