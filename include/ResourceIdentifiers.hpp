#pragma 

namespace Textures{
    enum ID{
        Eagle,
        Raptor,
        Desert,
        TitleScreen,
    };
}

namespace Fonts{
    enum ID{
        Main,
    };
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Textures, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Fonts, Fonts::ID> FontHolder;