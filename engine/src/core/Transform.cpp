//Transform.cpp
#include "core/Transform.h"


namespace ME{
	Transform::Transform() {}
	Transform::~Transform() {}

	MM::Vector3 Transform::getPosition(){
		return position;
	}
	MM::Vector3 Transform::getRotation(){
		return rotation;
	}
	MM::Vector3 Transform::getScale(){
		return scale;
	}
}