#pragma once

#include "World.hpp"

namespace Scenarios {
	// @TODO: when targetdestroyed, end simulation

	/** 
	 * note: would be too expensive to completely destroy and recreate the world for each scenario.
	 * Figure out a way to reset the world state instead, maybe differentiating between static world assets and dynamic.
	 * Maybe a static part of the world is a "target spawner" entity that spawns targets when needed and the target itself is a dynamic entity 
	 * that will be destroyed when the world resets.
	 **/

	class BaseScenario {
	public:
		BaseScenario() 
			: world(GWorldConfig{ -9.81f, 1000.0f }),
			simulation_time(10.0f),
			time_step(0.016f)
		{
		}
		~BaseScenario();

		virtual void Setup();
		virtual void Run();
		virtual void Teardown();


	protected:
		bool is_setup{ false };

		GWorld world;

		float simulation_time;
		float time_step;
	};
}