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

		void Run(float total_simulation_time, float time_step);

		entt::registry& GetRegistry();
		entt::dispatcher& GetDispatcher() { return dispatcher; }


	private:
		void Tick(float dt);
	private:
		// entity registry
		entt::registry registry;
		entt::dispatcher dispatcher;

		// world parameters
		float gravity{ -9.81f };
		float bounding_sphere_radius{ 1000.0f };
};