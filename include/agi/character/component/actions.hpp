/**
 * @file actions.hpp
 * @brief Action component (primarily) for characters.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Action_hpp__)
#define GF_Agi_Character_Comp_Action_hpp__

#include "definitions.h"
#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Action {
                    // TODO(Matthew): Implement.
                };

                namespace impl {
                    using P_Action  = struct {
                        ui32   priority;
                        Action action;
                    };

                    using P_Action_Comp = struct {
                        bool operator()(const P_Action& lhs, const P_Action& rhs) {
                            return lhs.priority < rhs.priority;
                        }
                    };
                }

                using Actions = Bounded_Priority_Queue<impl::P_Action, impl::P_Action_Comp, ACTION_P_QUEUE_SIZE>;
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Action_hpp__)
