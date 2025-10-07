#include <thread>
#include <chrono>
#include <iostream>

#include "World.hpp"
#include "Systems.hpp"

GWorld::GWorld() {
	registry = entt::registry{};
	dispatcher = entt::dispatcher{};
}

GWorld::GWorld(const GWorldConfig& config) : GWorld() {
	gravity = config.gravity;
	bounding_sphere_radius = config.bounding_sphere_radius;
}

GWorld::~GWorld() {
	
}

entt::registry& GWorld::GetRegistry() {
	return registry;
}

void GWorld::Run(float total_simulation_time, float time_step) {
	// count simulation steps so far
	int counter_steps = 0;

	// initialize clock
	std::chrono::steady_clock::time_point last_frame_time = std::chrono::steady_clock::now();


	float accumulated_time = 0.0f;
	while (accumulated_time < total_simulation_time) {
		
		while(last_frame_time + std::chrono::duration<float>(time_step) > std::chrono::steady_clock::now()) {
			// busy wait
			std::this_thread::yield();
		}

		// calculate delta time and FPS
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<float> frame_duration = now - last_frame_time;
		float dt = frame_duration.count();
		float fps = 1.0f / dt;

		// tick the world
		last_frame_time = now; // update last frame time before tick to avoid time spent in Tick() to be counted in dt
		Tick(dt);
		counter_steps++;

		// print out the info
		std::cout << "Step: " << counter_steps << "  DT: " << (dt * 1000.0f) << "ms  FPS: " << fps << " TOTAL TIME: " << accumulated_time << "s \n";
		// @TODO: write warning to console if dt > time_step

		accumulated_time += dt;
	}
}


void GWorld::Tick(float dt) {
	Systems::SysMovement movementSystem;
	Systems::SysCollision collisionSystem;
	Systems::SysWorldBounds worldBoundsSystem;
	Systems::SysPendingDestroy pendingDestroySystem;

	movementSystem.Update(*this, gravity, dt);
	collisionSystem.Update(*this);
	worldBoundsSystem.Update(*this, bounding_sphere_radius);
	pendingDestroySystem.Update(*this);
}
