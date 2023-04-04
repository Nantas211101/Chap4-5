#pragma once
#include <SFML/Graphics.hpp>

namespace Category
{
    enum Type
    {
        None = 0,
        Scene = 1 << 0,
        PlayerAircraft = 1 << 1,
        AlliedAircraft = 1 << 2,
        EnemyAircraft = 1 << 3,
    };
}

// unsigned int anyAircraft    = Category::PlayerAircraft 
//                             | Category::AlliedAircraft 
//                             | Category::EnemyAircraft;