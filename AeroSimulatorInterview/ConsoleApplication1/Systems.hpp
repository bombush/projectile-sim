#pragma once

#include <entt/entt.hpp>

#include "World.hpp"

namespace Systems {


	class SysMovement
	{
		public:
			void Update(GWorld& world, float gravity, float dt);
	};

	class SysCollision
	{
		public:
			void Update(GWorld& world);
	};

	class SysWorldBounds
	{
		public:
			void Update(GWorld& world,  float bounding_sphere_radius);
	};
}