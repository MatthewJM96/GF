/**
 * @file desire_marshaller.h
 * @brief Provides functions for selecting desires based on duties, personality, needs and so on.
 */

#pragma once

#if !defined(GF_AGI_Character_Desire_Marshaller_h__)
#define GF_AGI_Character_Desire_Marshaller_h__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Desire_Marshaller {
                void update_desires(Common& common, Entity& desirer);
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_AGI_Character_Desire_Marshaller_h__)
