/**
 * @file risks.hpp
 * @brief Risk component (primarily) for characters. This entails both immediate risks
 * (e.g. threats to life) and upcoming risks (e.g. running out of resource related to
 * a need or desire).
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Risk_hpp__)
#define GF_Agi_Character_Comp_Risk_hpp__

#include "definitions.h"
#include "types.h"

#include "actions.hpp"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Risk {
                    // The target of the source of risk.
                    Entity target;
                    // Data needed for determining the possible set of actions to mitigate the risk.
                    void*  data;
                    // Determines the action set capable of mitigating the risk with priorities indicating estimate of chance of success.
                    Actions (*determine_action_set)(Entity& perceiver, Entity& target, void* data);
                };

                namespace impl {
                    using P_Risk  = struct {
                        ui32 priority;
                        Risk risk;
                    };

                    using P_Risk_Comp = struct {
                        bool operator()(const P_Risk& lhs, const P_Risk& rhs) {
                            return lhs.priority < rhs.priority;
                        }
                    };
                }

                using Risks = Bounded_Priority_Queue<impl::P_Risk, impl::P_Risk_Comp, RISKS_P_QUEUE_SIZE>;
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Risk_hpp__)
