#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.hpp"
#include <array>
#include "CommandQueue.hpp"
const std::string Path_Eagle = "./resource/eagle.png"; // the adress will be use when you run the .exe which mean the address should according to the place you call exe
const std::string Path_Raptor = "./resource/Raptor.jpg";
const std::string Path_Desert = "./resource/Desert.jpg";

class World : private sf::NonCopyable
{
public:
    explicit World(sf::RenderWindow &window);
    void update(sf::Time dt);
    void draw();

private:
    void loadTextures();
    void buildScene();

private:
    void setBackground();
    void setAirplanes();

private:
    void setLeader();
    void setEscort(bool isleft);

    // getting the CommandQueue
public:
    auto getCommandQueue() -> CommandQueue&;

private:
    enum Layer
    {
        Background,
        Air,
        LayerCount
    };

private:
    sf::RenderWindow &mWindow;
    sf::View mWorldView;
    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    Aircraft *mPlayerAircraft;
    float mScrollSpeed;
    CommandQueue mCommandQueue;

    TextureHolder mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode *, LayerCount> mSceneLayers;
};