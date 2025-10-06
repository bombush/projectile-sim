#include "Systems.hpp"
#include "Components.hpp"
#include "entt/entt.hpp"

namespace Systems {

	void SysMovement::Update(const entt::registry& registry, float gravity, float dt)
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
}