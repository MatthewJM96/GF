/**
 * @file registrar.h
 * @brief Provides functions for adding, editing and removing organisations from the game entity registry.
 */

#pragma once

#if !defined(GF_AGI_Org_Registrar_h__)
#define GF_AGI_Org_Registrar_h__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Org {
            namespace Registrar {
                Entity create_org(Common& common);

                void destroy_org(Common& common, Entity org);
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_AGI_Org_Registrar_h__)
