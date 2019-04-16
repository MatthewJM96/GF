/**
 * @file org_memberships.hpp
 * @brief Organisation membership components for entities.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Orgs_hpp__)
#define GF_Agi_Character_Comp_Orgs_hpp__

#include "types.h"

#include "agi/org/component/members.hpp"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Org_Membership {
                    /**
                     * The date this entity joined the organisation.
                     */
                    ui64 date_joined;
                    /**
                     * The rank of this entity in the organisation.
                     */
                    GFAGI::Org::Comp::Members::Rank_ID rank;
                };

                /**
                 * The collection of organisation memberships this entity has.
                 * 
                 * Key is the entity representing the organisation itself.
                 *   Probably don't want to storing this in game saves rather than
                 *   unique identifier of org, depending on how we save orgs.
                 */
                using Org_Memberships = std::unordered_map<Entity, Org_Membership>;
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Orgs_hpp__)
