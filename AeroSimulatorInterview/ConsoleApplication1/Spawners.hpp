#pragma once

#include <entt/entt.hpp>

#include "Components.hpp"
#include "Types.hpp"
#include "World.hpp"

namespace Spawners {
	entt::entity SpawnTarget(GWorld& world, const Types::GVector& position, float radius);
	entt::entity SpawnProjectile(GWorld& world, const Types::GVector& position, const Types::GVector& muzzle_velocity, float radius, float drag_coefficient);
	entt::entity SpawnTerrain(GWorld& world, float height);
}