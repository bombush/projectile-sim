#pragma once

#include <entt/entt.hpp>
#include "World.hpp"

namespace Systems {

	class SysMovement
	{
	public:
		// Updates movement of entities based on velocity, acceleration, and gravity
		void Tick(GWorld& world, float gravity, float dt);
	};

	class SysCollision
	{
	public:
		// Checks collision between projectiles, targets, and terrain
		void Tick(GWorld& world);
	};

	class SysWorldBounds
	{
	public:
		// Checks if entities are out of world bounds
		void Tick(GWorld& world, float bounding_sphere_radius);
	};
}