#include "stdafx.h"
#include "agi/character/risk_marshaller.h"

#include "agi/character/component/risks.hpp"
#include "world/inhabitants.h"

void GFAGI::Character::Risk_Marshaller::alert_to_risk(Common& common, Entity& alerted_char, ui32 risk_factor, Comp::Risk& risk) {
    using namespace GFAGI::Character::Comp;

    // Registry of all entities.
    Registry& reg = common.registry;

    // Get risk queue of this character.
    auto chars = reg.view<Risks>();
    Risks& alerted_risks = chars.get(alerted_char);

    // Emplace our new risk.
    alerted_risks.emplace(risk_factor, risk);
}
