#pragma once

#include <thread>
#include <string>
//#include "../../Engine/ObjectManager/ObjectManager.h"

enum ArcheType {
    AT_NONE,

    // Player
    AT_PLAYER,

    AT_END
};

inline ArcheType ArcheTypeConverter(const std::string& key)
{
    // Default archetype
    if (key == "NONE")
        return AT_NONE;

    // Player
    else if (key == "PLAYER")
        return AT_PLAYER;

    // Default
    else
        return AT_NONE;
}

inline void RegisterArcheTypes(void)
{
    //std::thread at_thread[AT_LOAD_END];
    //ObjectManager::AddArcheType(AT_PLAYER, "Resource/Data/ArcheType/Player/Player.json");
    //at_thread[AT_PLAYER] = std::thread(ObjectManager::AddArcheType, AT_PLAYER, "Resource/Data/ArcheType/Player.json");
}