/**
 * @file personality.hpp
 * @brief Personality component (primarily) for characters.
 */

#pragma once

#if !defined(GF_Agi_Character_Comp_Personality_hpp__)
#define GF_Agi_Character_Comp_Personality_hpp__

#include "types.h"

namespace GnomeFortress {
    namespace AGI {
        namespace Character {
            namespace Comp {
                struct Personality {
                    /**
                     * The degree to which a character will trust another character.
                     *   Increasingly negative values indicate greater default suspicion.
                     *   Increasingly positive values indicate greater default trust.
                     */
                    i8 gullibility;
                    /**
                     * The degree to which a character will connect with others and do social activities.
                     *   Increasingly negative values indicate greater default introvertedness.
                     *   Increasingly positive values indicate greater default extravertedness.
                     */
                    i8 sociability;
                    /**
                     * The degree to which a character will get on with other characters and be initiailly well-disposed.
                     *   Increasingly negative values indicate greater default hostility.
                     *   Increasingly positive values indicate greater default agreeability.
                     */
                    i8 friendliness;
                    /**
                     * The degree to which a character will seek new experiences, be interested in new ideas and be inclined to certain professions.
                     *   Increasingly negative values indicate greater default pragmatism/cautiousness.
                     *   Increasingly positive values indicate greater default openness/inventiveness.
                     */
                    i8 curiousness;
                    /**
                     * The degree to which a character will be organised and disciplined, being more consistent in fulfilling others' needs.
                     *   Increasingly negative values indicate greater default self-discipline/efficiency.
                     *   Increasingly positive values indicate greater default easiness/carelessness.
                     */
                    i8 conscientiousness;
                    /**
                     * The degree to which a character will be confident in their own achievements and be harder to influence without establishing real trust.
                     *   Increasingly negative values indicate greater default sensitivity/insecurity.
                     *   Increasingly positive values indicate greater default security.
                     */
                    i8 confidence;
                };
            }
        }
    }
}
namespace GFAGI = GnomeFortress::AGI;

#endif // !defined(GF_Agi_Character_Comp_Personality_hpp__)
