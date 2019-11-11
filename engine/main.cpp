#include <SFML/Graphics.hpp>

#include "common/assert.h"
#include "common/typedef.h"
#include "../builds/meConfig.h"
#include <iostream>
#include <fstream>

#include "common/Locator.h"
#include "common/console/Console.h"
#include "core/GameWorldModule.h"
#include "core/RenderModule.h"
#include "core/resource/ResourceHolder.hpp"

#include "math/Vector3.h"
#include "common/datastructures/Array.h"

#include "common/Random.h"

#include "common/Helper.h"
#include "core/IEntityComponent.h"
#include "core/TestComponent.h"
#include "core/Entity.h"
#include <algorithm>
#include <vector>

#include <string>
#include <typeinfo>

int main(int argc, char* argv[]){

	// List of the modules
	#pragma region List of modules
	Console locConsole;
	// Random locRandom;
	RenderModule modRenderModule;
	ME::GameWorldModule modGameWorld;
	#pragma endregion

	#pragma region Resources
	ResourceHolder<Textures::ID, sf::Texture> texturesHolder;
	texturesHolder.Load(Textures::ID::Basic_Quad, Textures::path + "basic_quad.png");
	texturesHolder.Get(Textures::ID::Basic_Quad);
	#pragma endregion

	#pragma region Start up the engine modules in CORRECT order
	Locator::initialize();
	locConsole.startUp();
	Locator::provide(&locConsole);
	// random.StartUp();
	// Locator::provide(&random);
	locConsole.engineStartMessage(argc, argv);
	// ...
	modRenderModule.StartUp();
	modGameWorld.StartUp();
	
	// std::fstream file;
	// file.open("test.csv", std::fstream::out);
	// for(size_t i = 0, iLen = 200; i < iLen; i++){
	// 	auto var = random.GetEqualFloat();
	// 	console.print("[i]" + Helper::toString(var));
	// 	file << Helper::toString(var) << std::endl;
	// }
	// file.close();
	#pragma endregion

	#pragma region Run the game

	//modGameWorld.Run();

	#pragma endregion

	
	#pragma region Shut down the engine modules in REVERSE order
	modGameWorld.ShutDown();
	modRenderModule.ShutDown();
	// ... 
	// Random::ShutDown();
	locConsole.engineEndMessage();
	locConsole.shutDown();
	#pragma endregion
	return 0;
}
