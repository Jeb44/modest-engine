//Console.cpp
#include "common/console/Console.h"

Console::Console() :
headerSize(1) // ,
// currentBuffer(&buffers[0]),
// nextBuffer(&buffers[1])
{}

Console::~Console() {}

void Console::startUp(){
	// printer = new NullPrinter(); // use cmake to specify start-console
	printer = new WinConsolePrinter();
	Locator::provide(this);
}

void Console::shutDown(){
	delete printer;
}

void Console::assignPrinter(IConsolePrinter* printer){
	this->printer = printer; 
}

void Console::print(const C8* message, const C8* sender){
	if(sender[0] != '\0' && sender != nullptr){
		printer->print(buildSenderMessage(message, sender));
		return;
	}
	printer->print(message);
}

void Console::print(const std::string message, const std::string sender){
	std::string newMessage = message;
	if(sender != ""){
		newMessage = buildSenderMessage(message, sender);
	}
	// printer->print(newMessage);
	messages.push_back(&newMessage);
}

void Console::engineStartMessage(int argc, char* argv[]){
	std::string message = "";
	message += "[Modest-Engine] Version " + ME::getVersionNumber() + "\n";
	message += "Execution Path: " + std::string(argv[0]) + "\n";

	printer->print(message);
}

void Console::engineEndMessage(){
	printer->print("[END] Press any key to close program...");
	getchar(); // IConsolePrinter Command?
}

const C8* Console::buildSenderMessage(const C8* message, const C8* sender){
	return std::string("[" + std::string(sender) + "] " + std::string(message)).c_str();
}
std::string Console::buildSenderMessage(const std::string message, const std::string sender){
	return "[" + sender + "] " + message;
}

// std::cout << "[" << typeid(sender) << ": " << QUOTE(sender) << "] " << message << std::endl;
// std::cout<<typeid(A).name()<<"\t"<< quote(A) <<"\n";

void Console::drawNextFrame(F32 frameRate){

	// Clear next Buffer
	// clear();

	// Write into next Buffer
	addFrameHeader(frameRate);
	removeOverdueMessages();
	drawEmptySpaces();
	drawMessages();
	
	// Swap buffers
	// swapBuffer();
	// print(*currentBuffer);
}

// void Console::swapBuffer(){
// 	std::string* temp = currentBuffer;
// 	currentBuffer = nextBuffer;
// 	nextBuffer = temp;
// }



// Printing Frames
void Console::addFrameHeader(F32 frameRate){
	std::string message = "[Modest-Engine]"/*" Framerate: " + Helper::toString(frameRate)*/;
	
	messages.push_back(&message);
}

void Console::removeOverdueMessages(){
	auto numOfElemensToDelete = messages.size() - printer->getRows() - headerSize;

	if(numOfElemensToDelete <= 0){
		for(size_t i = 0, iLen = numOfElemensToDelete; i < iLen; i++){
			std::string newLine = "\n";
			messages.push_back(&newLine);
		}		
	} 
	else{
		for(size_t i = 0, iLen = numOfElemensToDelete; i < iLen; i++){
			auto element = messages.front();
			messages.pop_front();
			delete element;
		}
	}
}

void Console::drawEmptySpaces(){
	// insert required empty spaces (so the last message is on the bottom)
}

void Console::drawMessages(){
	// print list in reverse order
	for(auto it = messages.begin(); it != messages.end(); it++){
		auto element = messages.front();
		messages.pop_front();
		delete element;
	}
}