// ResourceHolder.hpp
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <map>
#include <memory>
#include <stdexcept>

#define RESOURCE_PATH "../res/"

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

namespace Resources{
	const std::string path = "../res/";
	enum struct ID{
		Test
	};
}

namespace Textures{
	const std::string path = "../res/textures/";
	enum struct ID{
		Basic_Quad
	};
}