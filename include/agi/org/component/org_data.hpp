/**
 * @file org_data.hpp
 * @brief Generic organisation data component for organisation entities.
 */

#pragma once

#if !defined(GF_Agi_Org_Comp_Org_hpp__)
#define GF_Agi_Org_Comp_Org_hpp__

#include "types.h"

#include "members.hpp"

namespace GnomeFortress {
    namespace AGI {
        namespace Org {
            namespace Comp {
                struct Org_Data {
                    /**
                     * Name of the organisation.
                     */
                    char* name;
                    /**
                     * In-game date the organisation was founded.
                     */
                    ui64  date_founded;
                    /**
                     * The number of members the organisation has.
                     */
                    ui16  member_count;
                    /**
                     * The default starting rank of a new member.
                     */
                    GFAGI::Org::Comp::Members::Rank_ID default_starting_rank;
                    // TODO(Matthew): Common data points for all organisations.
                };
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Org_Comp_Org_hpp__)
