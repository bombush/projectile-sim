#pragma once

#include <entt/entt.hpp>
#include "Types.hpp"

class GWorld {
	public:
		GWorld();
		~GWorld();

		void Tick(float dt);


	private:
		entt::registry registry;
		float gravity{ -9.81f };
};