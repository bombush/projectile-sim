#pragma once

#include "World.hpp"

namespace Scenarios {
	// @TODO: when targetdestroyed, end simulation
	class BaseScenario {
	public:
		virtual void Setup();
		virtual void Run();
		virtual void Teardown();

		void SpawnTarget();
		void SpawnProjectile();
		void SpawnTerrain();

	protected:
		GWorld world;

		int num_targets;
		int num_projectiles;
		int num_terrains;
		float simulation_time;
		float time_step;
		float gravity;
		float world_bounds_radius;
	};
}