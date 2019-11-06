//ResourceHolder.cpp
#include "core/resource/ResourceHolder.h"

// This file only exists, so cmake & include-path
// can work accoding to the current setup.

template<typename Identifier, typename Resource>
void ResourceHolder<Identifier, Resource>::Load(Identifier id, const std::string& filename){
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());
	if(!resource->loadFromFile(filename)){
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	// If loading successful, insert resource to map
	insertResource(id, std::move(resource));
}

template <typename Identifier, typename Resource>
template <typename Parameter>
void ResourceHolder<Identifier, Resource>::Load(Identifier id, const std::string& filename, const Parameter& secondParam){
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam)){
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	// If loading successful, insert resource to map
	insertResource(id, std::move(resource));
}

template <typename Identifier, typename Resource>
Resource& ResourceHolder<Identifier, Resource>::Get(Identifier id){
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Identifier, typename Resource>
const Resource& ResourceHolder<Identifier, Resource>::Get(Identifier id) const{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Identifier, typename Resource>
void ResourceHolder<Identifier, Resource>::InsertResource(Identifier id, std::unique_ptr<Resource> resource) {
	// Insert and check success
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}