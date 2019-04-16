/**
 * @file risk_marshaller.h
 * @brief Provides functions for adding risks to characters.
 */

#pragma once

#if !defined(GF_AGI_Character_Risk_Marshaller_h__)
#define GF_AGI_Character_Risk_Marshaller_h__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Risk_Marshaller {
                void alert_to_risk(Common& common, Entity& alerted_char, ui32 risk_factor, Comp::Risk& risk);
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_AGI_Character_Risk_Marshaller_h__)
