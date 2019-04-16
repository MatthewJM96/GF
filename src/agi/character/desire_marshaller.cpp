#include "stdafx.h"
#include "agi/character/desire_marshaller.h"

#include "agi/character/component/desires.hpp"
#include "agi/character/component/duties.hpp"
#include "agi/character/component/needs.hpp"
#include "agi/character/component/personality.hpp"
#include "agi/character/component/risks.hpp"

void GFAGI::Character::Desire_Marshaller::update_desires(Common& common, Entity& desirer) {
    // TODO(Matthew): For now assuming all entities with desires also have needs, personality, duties etc.

    using namespace GFAGI::Character::Comp;

    // Registry of all entities.
    Registry& reg = common.registry;

    // Get view over all entities with desires.
    auto desirers = reg.view<Desires, Duties, Needs, Personality, Risks>();

    // Get all related components of the given entity we're updating.
    [[maybe_unused]] Desires&     desires     = desirers.get<Desires>(desirer);
    [[maybe_unused]] Duties&      duties      = desirers.get<Duties>(desirer);
    [[maybe_unused]] Needs&       needs       = desirers.get<Needs>(desirer);
    [[maybe_unused]] Personality& personality = desirers.get<Personality>(desirer);
    [[maybe_unused]] Risks&       risks       = desirers.get<Risks>(desirer);

    // TODO(Matthew): Implement rest.
}
