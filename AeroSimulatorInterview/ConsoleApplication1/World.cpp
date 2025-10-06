#include "World.hpp"
#include "Systems.hpp"

GWorld::GWorld() {
	registry = entt::registry{};
}

GWorld::GWorld(const GWorldConfig& config) : GWorld() {
	gravity = config.gravity;
	bounding_sphere_radius = config.bounding_sphere_radius;
}

GWorld::~GWorld() {
	
}

void GWorld::Tick(float dt) {
	Systems::SysMovement movementSystem;
	Systems::SysCollision collisionSystem;
	Systems::SysWorldBounds worldBoundsSystem;

	movementSystem.Update(registry, gravity, dt);
	collisionSystem.Update(registry);
	worldBoundsSystem.Update(registry, bounding_sphere_radius);

	//movementSystem.Update(dt);
	// Other systems would be updated here as well
}