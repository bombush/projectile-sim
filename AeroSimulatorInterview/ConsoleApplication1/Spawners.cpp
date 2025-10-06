#include "Spawners.hpp"
#include "Components.hpp"

using namespace Components;

namespace Spawners {
	entt::entity SpawnTarget(GWorld& world, const Types::GVector& position, float radius) {
		auto registry = world.GetRegistry();

		auto entity = world.GetRegistry().create();
		registry.emplace<CompPosition>(entity, position);
		registry.emplace<CompVelocity>(entity, Types::GVector{ 0.0f, 0.0f, 0.0f });
		registry.emplace<CompCollisionSphere>(entity, radius);
		registry.emplace<TagTarget>(entity);

		return entity;
	}

	entt::entity SpawnProjectile(GWorld& world, const Types::GVector& position, const Types::GVector& muzzle_velocity, float radius, float drag_coefficient) {
		auto registry = world.GetRegistry();
		auto entity = world.GetRegistry().create();
		registry.emplace<CompPosition>(entity, position);
		registry.emplace<CompVelocity>(entity, muzzle_velocity);
		registry.emplace<CompAcceleration>(entity, Types::GVector{ 0.0f, 0.0f, 0.0f }); // no acceleration except gravity
		registry.emplace<CompCollisionSphere>(entity, radius);
		registry.emplace<TagProjectile>(entity);

		return entity;
	}

	entt::entity SpawnTerrain(GWorld& world, float z_position) {
		auto registry = world.GetRegistry();
		auto entity = world.GetRegistry().create();
		registry.emplace<CompTerrainCollision>(entity, z_position);
		registry.emplace<TagTerrain>(entity);
		return entity;
	}
} // namespace Spawners