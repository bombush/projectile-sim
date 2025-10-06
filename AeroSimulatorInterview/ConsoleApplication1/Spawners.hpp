#pragma once

#include "Components.hpp"
#include "Types.hpp"
#include "World.hpp"

namespace Spawners {
	void SpawnTarget(GWorld& world, const Types::GVector& position, float radius);
	void SpawnProjectile(GWorld& world, const Types::GVector& position, const Types::GVector& muzzle_velocity, float radius, float drag_coefficient);
	void SpawnTerrain(GWorld& world, float height);
}