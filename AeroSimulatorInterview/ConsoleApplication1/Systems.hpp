#pragma once

#include <entt/entt.hpp>

namespace Systems {


	class SysMovement
	{
		void Update(entt::registry& registry, float gravity, float dt);
	};

	class SysCollision
	{
		void Update(entt::registry& registry);
	};

	class SysWorldBounds
	{
		void Update(entt::registry& registry, float bounding_sphere_radius);
	};
}