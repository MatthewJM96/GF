#include "stdafx.h"
#include "agi/org/registrar.h"

#include "physics/component/position.hpp"

Entity GFAGI::Org::Registrar::create_org(Common& common) {
    // Registry of all entities.
    Registry& reg = common.registry;

    const Entity org = reg.create();

    //reg.assign<M>(org);
    // TODO(Matthew): Assign other default properties.

    return org;
}

void GFAGI::Org::Registrar::destroy_org(Common& common, Entity org) {
    common.registry.destroy(org);
}
