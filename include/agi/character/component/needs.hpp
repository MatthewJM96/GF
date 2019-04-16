/**
 * @file needs.hpp
 * @brief Needs component (primarily) for characters.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Needs_hpp__)
#define GF_Agi_Character_Comp_Needs_hpp__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Needs {
                    /**
                     * Represents the hunger of the character.
                     *   - Hunger doesn't directly affect desires but does add an incremental
                     *     risk which must be mitigated.
                     */
                    ui8 hunger;
                    /**
                     * Represents the thirst of the character.
                     *   - Thirst doesn't directly affect desires but does add an incremental
                     *     risk which must be mitigated.
                     */
                    ui8 thirst;
                    /**
                     * Represents the physical tiredness of the character.
                     *   - Physical fatigue doesn't directly affect desires but does add an incremental
                     *     risk which must be mitigated.
                     *   - Physical fatigue does affect the character's ability to execute physical actions.
                     *   - At its extreme, it will cause the character to lose consciousness.
                     */
                    ui8 physical_fatigue;
                    /**
                     * Represents the mental tiredness of the character.
                     *   - Mental fatigue doesn't directly affect desires but does add an incremental
                     *     risk which must be mitigated.
                     *   - Mental fatigue does affect the character's ability to execute physical, mental and social actions.
                     *   - At its extreme, it will cause the character to lose consciousness.
                     */
                    ui8 mental_fatigue;
                    /**
                     * Represents the adrenaline currently released in the character.
                     *   - Adrenaline overrides physical and mental fatigue for short periods.
                     *   - Adrenaline causes both physical and mental fatigue to drain at a greater rate.
                     *   - Adrenaline affects the character's ability to execute gross physical actions beneficially,
                     *     and fine physical actions negatively.
                     */
                    ui8 adrenaline;
                    // TODO(Matthew): Do we want both current and long-term indicators for stress?
                    /**
                     * Represents the stress of the character.
                     *   - Stress affects the character's ability to execute mental and social actions.
                     *   - Stress builds up by being exposed to risks both for self and for characters this character cares for.
                     *     - The way in which stress builds up for different causes depends on personality.
                     */
                    ui8 stress;
                    /**
                     * Represents the contentment of the character.
                     *   - Contentment affects the character's ability to execute mental and social actions.
                     *   - Contentment builds up by contact with characters this character cares for, and fulfilment of desires and duties.
                     *     - The way in which contentment builds up for different causes depends on personality.
                     */
                    ui8 contentment;
                };
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Needs_hpp__)
