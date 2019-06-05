#include <iostream>

#include "common/assert.h"
#include "common/typedef.h"
#include "../builds/meConfig.h"


#include "common/Locator.h"
#include "core/GameWorldModule.h"
#include "common/console/Console.h"

#include "math/Vector3.h"
#include "core/Goomba.h"

#include <string>
#include <typeinfo>

#define MS_PER_UPDATE 60

int main(int argc, char* argv[]){

	// List of the modules
	ME::GameWorldModule modGameWorld;
	Console console;

	// Start up engine in the CORRECT order
	console.startUp();
	console.engineStartMessage(argc, argv);
	modGameWorld.startUp();
	// ...

	#pragma region First Code
	ME::Entity* goomba = new Goomba("Goomba");
	while(false){
		for(size_t i = 0, iLen = 10; i < iLen; i++){
			goomba->getTransform()->setPosition(MM::Vector3(i, 0.0f, 0.0f));
		}
		for(size_t i = 10, iLen = 0; i > iLen; i--){
			goomba->getTransform()->setPosition(MM::Vector3(i, 0.0f, 0.0f));
		}
		console.print(goomba->getTransform()->getPosition()->toString()); // "Render"
	}
	#pragma endregion

	#pragma region Second Code
	// ME::Entity* betterGoomba = new Goomba("Goomba");
	ME::Entity* betterGoomba = new Goomba("Goomba");
	B8 walkLeft = false;
	F32 xPos = 0.0f;
	while(false){
		if(walkLeft){
			xPos--;
			if(xPos == 0.0f){
				walkLeft = false;
			}
		}
		else
		{
			xPos++;
			if(xPos == 10.0f){
				walkLeft = true;
			}
		}

		betterGoomba->getTransform()->setPosition(MM::Vector3(xPos, 0.0f, 0.0f));
		
		// User Input & Rendering
		console.print(betterGoomba->getTransform()->getPosition()->toString());
	}
	#pragma endregion

	#pragma region Thid Code I
	// Other Goombas Variables ...
	ME::Entity* fastGoomba = new Goomba("Fast Goomba");
	F32 fastGoombaXPos = 10.0f;
	F32 fastGoombaSpeed = 1.35f;
	B8 fastGoombaWalkLeft = false;
	
	while(false){
		// Other Goomba behaviour ...
		if(fastGoombaWalkLeft){
			fastGoombaXPos -= fastGoombaSpeed;
			if(fastGoombaXPos <= 5.0f){
				fastGoombaWalkLeft = false;
			}
		} else{
			fastGoombaXPos += fastGoombaSpeed;
			if(fastGoombaXPos >= 15.0f){
				fastGoombaWalkLeft = true;
			}
		}
		fastGoomba->getTransform()->setPosition(
			MM::Vector3(fastGoombaXPos, 1.0f, 0.0f)
		);

		// Other Goombas Rendering ...
		console.print("Fast G.: " + fastGoomba->getTransform()->getPosition()->toString());
	}	
	#pragma endregion

	#pragma region Thid Code II
	// Other Goombas Variables ...
	ME::Entity* flyingGoomba = new Goomba("Flying Goomba");
	F32 flyingGoombaYPos = 2.0f;
	B8 flyUp = true;
	while(false){
		// Other Goomba behaviour ...
		if(flyUp){
			flyingGoombaYPos++;
			if(flyingGoombaYPos >= 5.0f){
				flyUp = false;
			}
		} else{
			flyingGoombaYPos--;
			if(flyingGoombaYPos <= 1.0f){
				flyUp = true;
			}
		}
		flyingGoomba->getTransform()->setPosition(
			MM::Vector3(4.0f, flyingGoombaYPos, 0.0f)
		);

		//Rendering ...

		// Other Goombas Rendering ...
		console.print("Fly G.:  " + flyingGoomba->getTransform()->getPosition()->toString());
	}
	#pragma endregion


	// Run game
	modGameWorld.run();



	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	console.shutDown();
	// ...

	return 0;
}
