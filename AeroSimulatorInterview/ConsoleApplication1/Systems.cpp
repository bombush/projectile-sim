#include "Systems.hpp"
#include "Components.hpp"
#include "entt/entt.hpp"

namespace Systems {

	void SysMovement::Update(entt::registry& registry, float gravity, float dt)
	{
		registry.view<Components::CompPosition, Components::CompVelocity, Components::CompAcceleration>().each(
			[gravity, dt](auto &pos, auto &vel, auto &acc) {
				vel.x = vel.x + acc.x * dt;
				vel.y = vel.y + acc.y * dt;
				vel.z = vel.z + (acc.z + gravity) * dt;

				pos += vel * dt;
			}
		);
	}

	// check collision between projectiles and targets and terrain
	void SysCollision::Update(entt::registry& registry)
	{
		// lets's go with a naive implementation first with assuming that projectiles cannot collide with each other
		// if we want an efficient way to detect collisions between all objects, we need to implement broadphase collision detection

		auto targets = registry.view<Components::CompPosition, Components::CompCollisionSphere, Components::TagTarget>(); //@TODO: is this actually faster than just checking target tag?
		auto projectiles = registry.view<Components::CompPosition, Components::CompCollisionSphere, Components::TagProjectile>();

		for (auto projectile : projectiles)
		{
			for (auto target : targets)
			{
				auto& pos_projectile = projectiles.get<Components::CompPosition>(projectile);
				auto& pos_target = targets.get<Components::CompPosition>(target);
				auto& sphere_target = projectiles.get<Components::CompCollisionSphere>(target);
				auto& sphere_projectile = targets.get<Components::CompCollisionSphere>(projectile);

				auto dist = pos_projectile.dist(pos_target);
				if(dist < (sphere_projectile.radius + sphere_target.radius))
				{
					// collision!
					registry.destroy(projectile);
					registry.destroy(target);
					break; 
				}
				
			}
		}

		// check collision of projectiles with terrain
		auto terrains = registry.view<Components::CompTerrainCollision>();
		for (auto projectile : projectiles) {
			// for each projectile, check against all terrains
			for (auto& terrain : terrains) {
				auto& pos_projectile = projectiles.get<Components::CompPosition>(projectile);
				auto& pos_terrain = terrains.get<Components::CompTerrainCollision>(terrain);

				if (pos_projectile.z <= pos_terrain.height)
				{
					// collision with terrain!
					// @TODO: write to STDOUT

					registry.destroy(projectile); // destroy the projectile
					break;
				}

			}
		}
	}

	void SysWorldBounds::Update(entt::registry& registry, float bounding_sphere_radius)
	{
		auto entities = registry.view<Components::CompPosition>();
		for (auto entity : entities)
		{
			auto& pos = entities.get<Components::CompPosition>(entity);
			if (pos.length() > bounding_sphere_radius)
			{
				registry.destroy(entity); //@TODO: send out of bounds message
			}
		}
	}
}