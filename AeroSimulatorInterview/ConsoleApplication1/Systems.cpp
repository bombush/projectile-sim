#include <iostream>
#include <iomanip>
#include "entt/entt.hpp"

#include "Systems.hpp"
#include "Components.hpp"
#include "Events.hpp"


namespace Systems {

	void SysMovement::Tick(GWorld& world, float gravity, float dt)
	{
		world.GetRegistry().view<Components::CompPosition, Components::CompVelocity, Components::CompAcceleration>().each(
			[gravity, dt](auto &pos, auto &vel, auto &acc) {
				vel.x = vel.x + acc.x * dt;
				vel.y = vel.y + acc.y * dt;
				vel.z = vel.z + (acc.z + gravity) * dt;

				pos += vel * dt;
			}
		);

		world.GetRegistry().view<Components::CompVelocity, Components::CompPosition>().each(
			[](auto &vel, auto &pos) {
				// write out projectile location and velocity to the stdout and format with 2 decimal places and human readable description
				std::cout << "Projectile " << 1 << " Position: (" << std::fixed << std::setprecision(2) << pos.x << ", " << pos.y << ", " << pos.z << ") Velocity: (" << vel.x << ", " << vel.y << ", " << vel.z << ")\n";


				//world.GetDispatcher().trigger<Events::EvtProjectileMoved>(entity, dt);
			}
		);
	}

	// check collision between projectiles and targets and terrain
	void SysCollision::Tick(GWorld& world)
	{
		// lets's go with a naive implementation first with assuming that projectiles cannot collide with each other
		// if we want an efficient way to detect collisions between all objects, we need to implement broadphase collision detection

		auto targets = world.GetRegistry().view<Components::CompPosition, Components::CompCollisionSphere, Components::TagTarget>(); //@TODO: is this actually faster than just checking target tag?
		auto projectiles = world.GetRegistry().view<Components::CompPosition, Components::CompCollisionSphere, Components::TagProjectile>();

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
					world.GetRegistry().destroy(projectile);
					world.GetRegistry().destroy(target);
					break; 
				}
				
			}
		}

		// check collision of projectiles with terrain
		auto terrains = world.GetRegistry().view<Components::CompTerrainCollision>();
		for (auto projectile : projectiles) {
			// for each projectile, check against all terrains
			for (auto& terrain : terrains) {
				auto& pos_projectile = projectiles.get<Components::CompPosition>(projectile);
				auto& pos_terrain = terrains.get<Components::CompTerrainCollision>(terrain);

				if (pos_projectile.z <= pos_terrain.z_position)
				{
					// collision with terrain!
					// @TODO: write to STDOUT

					world.GetRegistry().destroy(projectile); // destroy the projectile
					break;
				}

			}
		}
	}

	void SysWorldBounds::Tick(GWorld& world, float bounding_sphere_radius)
	{
		auto entities = world.GetRegistry().view<Components::CompPosition>();
		for (auto entity : entities)
		{
			auto& pos = entities.get<Components::CompPosition>(entity);
			if (pos.length() > bounding_sphere_radius)
			{
				world.GetRegistry().destroy(entity); //@TODO: send out of bounds message
			}
		}
	}
}

// @TODO: projectiles or target could be spawned out of bounds?