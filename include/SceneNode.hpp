#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <assert.h>
#include "Category.hpp"
#include "Command.hpp"

// enum Layer
// {
//     Background,
//     Air,
//     LayerCount
// };
class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();

public:
    void attachChild(Ptr child);
    auto detachChild(const SceneNode &node) -> Ptr;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    // Updating
public:
    void update(sf::Time dt);

private:
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

    // Transform
public:
    auto getWorldTransform() -> sf::Transform const;
    auto getWorldPosition() -> sf::Vector2f const;

    // Command and category
private:
    auto getCategory() -> unsigned int const;
    void onCommand(const Command &command, sf::Time dt);

private:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};