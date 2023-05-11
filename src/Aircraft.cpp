// #include "Aircraft.hpp"

// auto toTextureID(Aircraft::Type type) -> Textures::ID
// {
//     switch (type)
//     {
//     case Aircraft::Eagle:
//         return Textures::Eagle;

//     case Aircraft::Raptor:
//         return Textures::Raptor;
//     }
//     return Textures::Eagle;
// }

// Aircraft::Aircraft(Type type, const TextureHolder &textures) : mType(type), mSprite(textures.get(toTextureID(type)))
// {
//     // Instead of using mSprite constructor as above we can:
//     // mSprite.setTexture(textures.get(toTextureID(type)))

//     // Set the origin to be the center
//     setCenterOrigin(mSprite);
// }

// void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     target.draw(mSprite, states);
// }

// auto Aircraft::getCategory() -> unsigned int const
// {
//     switch (mType)
//     {
//         case Eagle:
//             return Category::PlayerAircraft;
        
//         default:
//             return Category::EnemyAircraft;
//     }
// }