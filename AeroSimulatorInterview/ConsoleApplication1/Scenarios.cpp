#pragma once

#include "World.hpp"
#include "Scenarios.hpp"
#include "Spawners.hpp"

using namespace Scenarios;


BaseScenario::~BaseScenario() {
	this->Teardown();
}

void BaseScenario::Run() {
	if(false == is_setup) {
		this->Setup();
		is_setup = true;
	}
	// run the world simulation
	world.Run(simulation_time, time_step);
}

void BaseScenario::Teardown() {
}

void BaseScenario::Setup() {
	// spawn terrain and a single projectile
	Spawners::SpawnTerrain(world, 0.0f); // flat terrain at z = -10
	Spawners::SpawnProjectile(world, Types::GVector{ 0.0f, 0.0f, 10.0f }, Types::GVector{ 100.0f, 0.0f, 50.0f }, 0.1f, 0.01f);

	this->is_setup = true;
}
