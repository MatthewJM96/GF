#include "stdafx.h"
#include "agi/org/builder.h"

#include "agi/character/component/org_memberships.hpp"
#include "agi/org/component/members.hpp"
#include "agi/org/component/org_data.hpp"

bool GFAGI::Org::Builder::add_member(Common& common, Entity& char_to_add, Entity& org) {
    using namespace GFAGI::Character::Comp;
    using namespace GFAGI::Org::Comp;

    // Registry of all entities.
    Registry& reg = common.registry;

    // Get view over all entities with org memberships.
    auto chars = reg.view<Org_Memberships>();

    // Get char_to_add's org memberships.
    Org_Memberships& char_orgs = chars.get(char_to_add);
    // Check if char_to_add is already in org and, if they are, fail.
    for (auto& [char_org, membership] : char_orgs) {
        if (char_org == org) return false;
    }

    // Get view over all organisations.
    auto orgs = reg.view<Org_Data, Members>();

    // Get the org metadata of org.
    Org_Data& org_data = orgs.get<Org_Data>(org);

    // Get the members of org.
    Members& members = orgs.get<Members>(org);

    // TODO(Matthew): Can we drop this check and accept the resulting bugs? (Put in debug builds only?)
    // Check that the hierarchy includes the default rank.
    auto rank = members.hierarchy.find(org_data.default_starting_rank);
    if (rank == members.hierarchy.end()) {
        // TODO(Matthew): Send better fail message to caller.
        return false;
    }

    // Increment member count.
    org_data.member_count += 1;

    // TODO(Matthew): Implement (in-game) time stamping.
    // Add org membership to character.
    char_orgs.insert(std::make_pair(org, Org_Membership{
        org_data.default_starting_rank, 137
    }));

    // Add character with default rank.
    rank->second.push_back(char_to_add);

    // TODO(Matthew): Determine appropriate way(s) to add arc weights.
    //                  E.g. list of weights for some/all nodes (symmetric/asymmetric).
    //                       list of weights for ranks (symmetric/asymmetric).
    // Add character to graph.
    // [[maybe_unused]] Graph_Node node = members.graph->addNode();
    // TODO(Matthew): Do we add arcs between all members by default or only those we have weights for?

    return true;
}
