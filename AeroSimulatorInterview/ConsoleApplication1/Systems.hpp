#pragma once

#include <entt/entt.hpp>

namespace Systems {


	class SysMovement
	{
		void Update(const entt::registry& registry, float gravity, float dt);
	};
}