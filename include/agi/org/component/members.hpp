/**
 * @file members.hpp
 * @brief Member graph component for organisations.
 */

#pragma once

#if !defined(GF_Agi_Org_Comp_Members_hpp__)
#define GF_Agi_Org_Comp_Members_hpp__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Org {
            namespace Comp {
                /**
                 * Represents degree of awareness a given member of an organisation has of another.
                 */
                enum class Awareness_Kind {
                    EXISTS,
                    CONTACTABLE
                };

                struct Members {
                    /**
                     * Graph representing communication lines each member has in an organisation.
                     */
                    Graph* communication_lines;
                    struct {
                        /**
                         * The map of graph nodes to character entities.
                         */
                        Graph_Node_Map<Entity>* entity_map;
                        // TODO(Matthew): Make this dynamically calculated (chapter 7 of Lemon docs).
                        /**
                         * The map of (asymmetric) strength factor of each communication line a member has in an organisation.
                         * 
                         * Roughly represents the amount of trust the member has in this line of communication conveying their message effectively.
                         */
                        Graph_Arc_Map<f32>* strength;
                    } comm_lines_data;

                    /**
                     * Graph representing awareness each member has of other members in the organisation.
                     * 
                     * Useful, for example, when priorities mean going out of standard contact lines of organisation.
                     */
                    Graph* awareness;
                    struct {
                        /**
                         * The map of graph nodes to character entities.
                         */
                        Graph_Node_Map<Entity>* entity_map;
                        /**
                         * The map of (asymmetric) degrees of awareness a member has of another member in an organisation.
                         */
                        Graph_Arc_Map<Awareness_Kind>* kind;
                    } awareness_data;

                    using Rank_ID = ui16;
                    using Hierarchy = std::unordered_map<Rank_ID, std::vector<Entity>>;

                    /**
                     * Hierarchy structure of the organisation.
                     */
                    Hierarchy hierarchy;
                };
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Org_Comp_Members_hpp__)
