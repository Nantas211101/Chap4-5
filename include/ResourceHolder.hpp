#pragma once
#include <assert.h>

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
    };
}


template <typename Resource, typename Identifier>
class ResourceHolder {
   public:
    void load(Identifier id, const std::string& filename);

    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondpara);
    
    // Resource&           get(Identifier id);
    auto get(Identifier id) const -> Resource&;

   private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#include "../Template/ResourceHolder.inl"
