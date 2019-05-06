#include <iostream>

#include "common/typedef.h"
#include <assert.h>

//look up cmake tools
#include "meConfig.h"

int main(int argc, char* argv[]){	
	
	if(argc < 2){
		std::cout << argv[0] << " Version "
					<< ME_VERSION_MAJOR << "."
					<< ME_VERSION_MINOR << "."
					<< ME_VERSION_PATCH
					<< std::endl;
		return 1;
	}

	std::cout << std::endl << "[END] Press any key to close program..." << std::endl;
	getchar();

	return 0;
}