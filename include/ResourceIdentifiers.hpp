#pragma once
#include <SFML/Graphics.hpp>

namespace Textures{
    enum ID{
        Eagle,
        Raptor,
        Desert,
        TitleScreen,
        Menu,
        WhiteBackground,
        ButtonNormal,
        ButtonSelected,
        ButtonPressed,
    };
}

namespace Fonts{
    enum ID{
        Main,
        Label,
    };
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;