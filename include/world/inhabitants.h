/**
 * @file inhabitants.h
 * @brief Provides functions for managing inhabitants of the game world.
 */

#pragma once

#if !defined(GF_World_Inhabitants_h__)
#define GF_World_Inhabitants_h__

#include "types.h"

namespace GnomeFortress {
    struct Common;

    namespace World {
        struct Inhabitant_Connection {
            ui8 honesty;
            ui8 fairness;
            ui8 competence;
            ui8 disposition;
        };
        using Inhabitant_Connections = std::unordered_map<ui64, Inhabitant_Connection>;

        namespace Inhabitants {
            Inhabitant_Connection get_connection(Common& common, Entity& opinion_holder, Entity& opinions_of);
        }
    }
}
namespace GFW = GnomeFortress::World;

#endif // !defined(GF_World_Inhabitants_h__)
