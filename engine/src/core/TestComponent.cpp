//TestComponent.cpp
#include "core/TestComponent.h"

TestComponent::TestComponent() {}
TestComponent::~TestComponent() {}

void TestComponent::OnInit(Entity& go){}

void TestComponent::OnStart(Entity& go){}

void TestComponent::OnUpdate(Entity& go){
	Locator::getConsole()->print("I'm a test component!", "Test Component");
}

void TestComponent::OnFixedUpdate(Entity& go){}

void TestComponent::OnEnd(Entity& go){}