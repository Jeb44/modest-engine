//Transform.h
#pragma once

#include "math/Vector3.h"

namespace ME{
	class Transform {
	public:
		explicit Transform();
		virtual ~Transform();
		
		MM::Vector3 getPosition();
		MM::Vector3 getRotation();
		MM::Vector3 getScale();
		
	private:
		MM::Vector3 position;
		MM::Vector3 rotation;
		MM::Vector3 scale;
	};	
}