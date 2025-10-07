#include "Spawners.hpp"
#include "Components.hpp"

using namespace Components;

namespace Spawners {
	entt::entity SpawnTarget(GWorld& world, const Types::GVector& position, float radius) {
		auto entity = world.GetRegistry().create();
		world.GetRegistry().emplace<CompPosition>(entity, position);
		world.GetRegistry().emplace<CompVelocity>(entity, Types::GVector{ 0.0f, 0.0f, 0.0f });
		world.GetRegistry().emplace<CompCollisionSphere>(entity, radius);
		world.GetRegistry().emplace<TagTarget>(entity);

		return entity;
	}

	entt::entity SpawnProjectile(GWorld& world, const Types::GVector& position, const Types::GVector& muzzle_velocity, float radius, float drag_coefficient) {
		auto entity = world.GetRegistry().create();
		world.GetRegistry().emplace<CompPosition>(entity, position);
		world.GetRegistry().emplace<CompVelocity>(entity, muzzle_velocity);
		world.GetRegistry().emplace<CompAcceleration>(entity, Types::GVector{ 0.0f, 0.0f, 0.0f }); // no acceleration except gravity
		world.GetRegistry().emplace<CompCollisionSphere>(entity, radius);
		world.GetRegistry().emplace<TagProjectile>(entity);

		return entity;
	}

	entt::entity SpawnTerrain(GWorld& world, float z_position) {
		auto entity = world.GetRegistry().create();
		world.GetRegistry().emplace<CompTerrainCollision>(entity, z_position);
		world.GetRegistry().emplace<TagTerrain>(entity);
		return entity;
	}
} // namespace Spawners