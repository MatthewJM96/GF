/**
 * @file capabilities.hpp
 * @brief Capabilities component (primarily) for characters.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Capabilities_hpp__)
#define GF_Agi_Character_Comp_Capabilities_hpp__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Capabilities {
                    /**
                     * The strength of a character represents their capability to carry
                     * out tasks that require physical actions like breaking things,
                     * intimidating characters, carrying large amounts, fighting, etc.
                     */
                    ui8 strength;
                    /**
                     * The endurance of a character represents their capability to
                     * continue to carry out physical acts for longer periods and
                     * take more physical punishment.
                     */
                    ui8 endurance;
                    /**
                     * The constitution of a character represents their ability to
                     * handle poisons, infections, alcohol and so on. It also affects
                     * the mental determination of the character.
                     */
                    ui8 constitution;
                    /**
                     * The agility of a character represents their ability to do gross
                     * acts of movement such as jumping, dodging, climbing, and so on.
                     */
                    ui8 agility;
                    /**
                     * The dexterity of a character represents their ability to do fine
                     * acts of movement such as sleight of hand, using ranged weaponry,
                     * and so on.
                     */
                    ui8 dexterity;
                    /**
                     * The speed of a character represents their ability to do various
                     * physical tasks quicker.
                     */
                    ui8 speed;
                    /**
                     * The luck of a character causes all random outcomes to be tilted
                     * in the favour of the character.
                     */
                    ui8 luck;
                    /**
                     * The charisma of a character represents their ability to perform
                     * social tasks regardless of context.
                     */
                    ui8 charisma;
                    /**
                     * The creativity of a character represents their ability to find
                     * new solutions to problems, i.e. carrying out tasks like research,
                     * developing new spells etc.
                     */
                    ui8 creativity;
                    /**
                     * The intelligence of a character represents their ability to find new
                     * solutions to problems, i.e. carrying out tasks like research, developing
                     * new spells etc.
                     * 
                     * The difference between this and creativity is the particular kinds of
                     * spells, research etc. that it benefits.
                     */
                    ui8 intelligence;
                    /**
                     * The wisdom of a character represents their ability to disarm tough social
                     * situations, give information to other characters and use spells.
                     */
                    ui8 wisdom;
                };
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Capabilities_hpp__)
