/**
 * @file dependency_injector.hpp
 * @brief Depende.
 */

#pragma once

#if !defined(GF_Common_hpp__)
#define GF_Common_hpp__

#include "types.h"

#include "agi/character/component/actions.hpp"
#include "agi/character/component/capabilities.hpp"
#include "agi/character/component/desires.hpp"
#include "agi/character/component/needs.hpp"
#include "agi/character/component/personality.hpp"
#include "agi/org/component/org_data.hpp"
#include "world/inhabitants.h"

namespace GnomeFortress {
    struct Common {
        Registry& registry;
        struct {
            struct {
                GFW::Inhabitant_Connections connections;
            } inhabitants;
        } world;
        struct {
            struct {
                GFAGI::Character::Comp::Actions      actions;
                GFAGI::Character::Comp::Capabilities capabilities;
                GFAGI::Character::Comp::Desires      desires;
                GFAGI::Character::Comp::Needs        needs;
                GFAGI::Character::Comp::Personality  personality;
                GFW::Inhabitant_Connection           connection;
            } character;
            struct {
                GFAGI::Org::Comp::Org_Data org_data;
            } organisation;
        } defaults;
    };
}

#endif // !defined(GF_Common_hpp__)
