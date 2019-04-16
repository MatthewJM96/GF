/**
 * @file desires.hpp
 * @brief Desire component (primarily) for characters.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Desires_hpp__)
#define GF_Agi_Character_Comp_Desires_hpp__

#include "definitions.h"
#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                enum class DesirePolicy {
                    MAXIMISE,
                    MINIMISE,
                    // TODO(Matthew): Are there other desire policies? Are they simple enough to do this way or do we want to use functors?
                };

                struct Desire {
                    DesirePolicy policy;
                    // TODO(Matthew): Implement rest.
                };

                namespace impl {
                    using P_Desire  = struct {
                        ui32   priority;
                        Desire desire;
                    };

                    using P_Desire_Comp = struct {
                        bool operator()(const P_Desire& lhs, const P_Desire& rhs) {
                            return lhs.priority < rhs.priority;
                        }
                    };
                }

                using Desires = Bounded_Priority_Queue<impl::P_Desire, impl::P_Desire_Comp, DESIRE_P_QUEUE_SIZE>;
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Desires_hpp__)
