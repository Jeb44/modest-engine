//IEntityComponent.h
#pragma once

namespace ME {

	class IEntityComponent {
	public:
		virtual ~IEntityComponent();
		
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void destory() = 0;
		
	private:
		explicit IEntityComponent();
	};

}