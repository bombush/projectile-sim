#pragma once

#include "Types.hpp"

using namespace Types;

namespace Components {

	struct CompVelocity : GVector {};
	struct CompAcceleration : GVector {};
	struct CompMass { float value; };

	struct CompPosition : GVector {};

	struct CompCollisionSphere { float radius; };
	struct CompTerrainCollision { float height; };

	struct TagTarget {};
	struct TagProjectile {};
	struct TagTerrain {};

}




