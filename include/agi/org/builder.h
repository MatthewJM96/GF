/**
 * @file builder.h
 * @brief Provides functions for building organisations. Functions such as adding and removing members, name etc.
 */

#pragma once

#if !defined(GF_AGI_Org_Builder_h__)
#define GF_AGI_Org_Builder_h__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Org {
            namespace Builder {
                bool add_member(Common& common, Entity& char_to_add, Entity& org);
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_AGI_Org_Builder_h__)
