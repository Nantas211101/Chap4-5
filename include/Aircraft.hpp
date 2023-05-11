// #pragma once
// #include "Entity.hpp"
// #include "ResourceIdentifiers.hpp"
// #include "TextureManipulate.hpp"
// #include <SFML/Graphics.hpp>

// class Aircraft : public Entity // inherits indirectyly SceneNode
// {
// public:
//     enum Type
//     {
//         Eagle,
//         Raptor,
//     };

// public:
//     explicit Aircraft(Type type, const TextureHolder &textures);
//     virtual unsigned int const getCategory();

// private:
//     virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

// private:
//     Type mType;
//     sf::Sprite mSprite;
// };