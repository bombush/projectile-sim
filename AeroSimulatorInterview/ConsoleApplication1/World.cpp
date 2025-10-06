#include "World.hpp"
#include "Systems.hpp"

GWorld::GWorld() {
	registry = entt::registry{};
}

GWorld::~GWorld() {
	// Cleanup if necessary
}

void GWorld::Tick(float dt) {
	Systems::SysMovement movementSystem;
	//movementSystem.Update(dt);
	// Other systems would be updated here as well
}