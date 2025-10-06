#pragma once

#include <entt/entt.hpp>

namespace Systems {


	class SysMovement
	{
		public:
			void Update(entt::registry& registry, float gravity, float dt);
	};

	class SysCollision
	{
		public:
			void Update(entt::registry& registry);
	};

	class SysWorldBounds
	{
		public:
			void Update(entt::registry& registry, float bounding_sphere_radius);
	};
}