// ResourceHolder.hpp
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <map>
#include <memory>
#include <stdexcept>
#include <iostream>

namespace Resources{
	const std::string path = "../res/";
	enum ID{
		Test
	};
}

namespace Textures{
	const std::string path = "./../res/textures/";
	enum ID{
		Basic_Quad
	};
}

template<typename Identifier, typename Resource>
class ResourceHolder {
public:
	explicit ResourceHolder(){}
	virtual ~ResourceHolder(){}
	
	void Load(Identifier id, const std::string& filename);

	template<typename Parameter>
	void Load(Identifier id, const std::string& filename, const Parameter& secondParameter);

	Resource& Get(Identifier id);
	const Resource& Get(Identifier id) const;

private:
	void InsertResource(Identifier id, std::unique_ptr<Resource> resource);

	std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

#include "ResourceHolder.inl"