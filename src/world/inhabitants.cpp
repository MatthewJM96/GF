#include "stdafx.h"
#include "world/inhabitants.h"

ui64 get_index(Entity& opinion_holder, Entity& opinions_of) {
    return static_cast<ui64>(opinion_holder) + (static_cast<ui64>(opinions_of) << 32);
}

GFW::Inhabitant_Connection GFW::Inhabitants::get_connection(Common& common, Entity& opinion_holder, Entity& opinions_of) {
    // Get inhabitant data.
    Inhabitant_Connections& connections = common.world.inhabitants.connections;

    // Try to get the connection between the two characters. If none yet exists, set to default.
    // TODO(Matthew): For now working on assumption that the connection between characters is modified after
    //                the fact by factors such as personality rather than that being baked into its value.
    const auto& connection = connections.find(get_index(opinion_holder, opinions_of));
    if (connection != connections.end()) {
        return connection->second;
    } else {
        return common.defaults.character.connection;
    }
}
