/**
 * @file position.hpp
 * @brief Position component for entities.
 */

#pragma once

#if !defined(GF_Physics_Comp_Position_hpp__)
#define GF_Physics_Comp_Position_hpp__

#include "types.h"

namespace GnomeFortress {
    namespace Physics {
        namespace Comp {
            struct Position {
                // TODO(Matthew): Continuous vertical axis?
                f32v3 pos;
            };
        }
    }
}
namespace GFP = GnomeFortress::Physics;

#endif // !defined(GF_Physics_Comp_Position_hpp__)
