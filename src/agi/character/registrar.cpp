#include "stdafx.h"
#include "agi/character/registrar.h"

#include "agi/character/component/actions.hpp"
#include "agi/character/component/capabilities.hpp"
#include "agi/character/component/desires.hpp"
#include "agi/character/component/org_memberships.hpp"
#include "agi/character/component/personality.hpp"
#include "physics/component/position.hpp"

Entity GFAGI::Character::Registrar::create_npc(Common& common) {
    using namespace GFP::Comp;
    using namespace GFAGI::Character::Comp;

    // Registry of all entities.
    Registry& reg = common.registry;

    const Entity npc = reg.create();

    reg.assign<Actions>(npc)      = common.defaults.character.actions;
    reg.assign<Capabilities>(npc) = common.defaults.character.capabilities;
    reg.assign<Desires>(npc)      = common.defaults.character.desires;
    reg.assign<Needs>(npc)        = common.defaults.character.needs;
    reg.assign<Org_Memberships>(npc);
    reg.assign<Personality>(npc)  = common.defaults.character.personality;
    reg.assign<Position>(npc)     = { { 0.0f, 0.0f, 0.0f } };
    // TODO(Matthew): Assign other components and set default properties.

    return npc;
}

void GFAGI::Character::Registrar::destroy_npc(Common& common, Entity npc) {
    common.registry.destroy(npc);
}
