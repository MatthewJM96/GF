/**
 * @file registrar.h
 * @brief Provides functions for adding, editing and removing NPCs from the game entity registry.
 */

#pragma once

#if !defined(GF_AGI_Character_Registrar_h__)
#define GF_AGI_Character_Registrar_h__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Registrar {
                Entity create_npc(Common& common);

                void destroy_npc(Common& common, Entity entity);
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_AGI_Character_Registrar_h__)
