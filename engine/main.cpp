#include <iostream>

#include "common/typedef.h"
#include "assert.h"

#include "../builds/meConfig.h"

//TODO: add (console) logger (avoiding)
void engineStartMessage(int argc, char* argv[]){
	if(argc < 2){
		std::cout << "Path: "	<< argv[0] 	<< std::endl
		<< "Version "
			<< ME_VERSION_MAJOR << "."
			<< ME_VERSION_MINOR << "."
			<< ME_VERSION_PATCH
		<< std::endl;
	}
}

int main(int argc, char* argv[]){	
	
	engineStartMessage(argc, argv);

	std::cout << std::endl << "[END] Press any key to close program..." << std::endl;
	getchar();

	return 0;
}

