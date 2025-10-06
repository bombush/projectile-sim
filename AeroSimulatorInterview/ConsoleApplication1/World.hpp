#pragma once

#include <entt/entt.hpp>
#include "Types.hpp"

struct GWorldConfig {
	float gravity;
	float bounding_sphere_radius;
};

class GWorld {
	public:
		GWorld();
		GWorld(const GWorldConfig& config);
		~GWorld();

		// main simulation step
		void Tick(float dt);

		entt::registry& GetRegistry();


	private:
		// entity registry
		entt::registry registry;

		// world parameters
		float gravity{ -9.81f };
		float bounding_sphere_radius{ 1000.0f };
};