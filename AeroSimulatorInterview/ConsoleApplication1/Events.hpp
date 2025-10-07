#pragma once

namespace Events {
	enum class EDestroyReason {
		Collision,
		OutOfBounds,
		CollisionWithTerrain,
		HitByProjectile,
		LifetimeExpired
	};

	struct EventTargetDestroyed {
		EDestroyReason reason;
	};
	struct EventProjectileDestroyed {
		EDestroyReason reason;
	};
}