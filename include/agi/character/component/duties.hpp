/**
 * @file duties.hpp
 * @brief Duties component (primarily) for characters - duties in a Kantian sense.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Duty_hpp__)
#define GF_Agi_Character_Comp_Duty_hpp__

#include "definitions.h"
#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Duty {
                    // TODO(Matthew): Determine way to encapsulate the kind of duty.
                    //                  Probably create some kind of functor that determines an
                    //                  action policy or provides a collection of action options.
                };

                namespace impl {
                    using P_Duty  = struct {
                        ui32 priority;
                        Duty duty;
                    };

                    using P_Duty_Comp = struct {
                        bool operator()(const P_Duty& lhs, const P_Duty& rhs) {
                            return lhs.priority < rhs.priority;
                        }
                    };
                }

                using Duties = Bounded_Priority_Queue<impl::P_Duty, impl::P_Duty_Comp, DUTY_P_QUEUE_SIZE>;
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Duty_hpp__)
