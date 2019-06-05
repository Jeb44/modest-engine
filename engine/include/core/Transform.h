//Transform.h
#pragma once

#include "math/Vector3.h"

namespace ME{
	class Transform {
	public:
		explicit Transform();
		virtual ~Transform();
		
		
		void setPosition(MM::Vector3 newPosition);
		void setRotation(MM::Vector3 newRotation);
		void setScale(MM::Vector3 newScale);

		MM::Vector3* getPosition();
		MM::Vector3* getRotation();
		MM::Vector3* getScale();
		
	private:
		MM::Vector3 position;
		MM::Vector3 rotation;
		MM::Vector3 scale;
	};	
}