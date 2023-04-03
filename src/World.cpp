#include "../include/World.hpp"

World::World(sf::RenderWindow &window) : 
    mWindow(window), 
    mWorldView(window.getDefaultView()), 
    mWorldBounds(
        0.f,                                                    // left X position
        0.f,                                                    // top Y position
        mWorldView.getSize().x,                                 // width
        2000.f),                                                // height
    mSpawnPosition(
        mWorldView.getSize().x / 2.f,                           // X position
        mWorldBounds.height - mWorldView.getSize().y / 2.f),  // Y position
    mPlayerAircraft(nullptr),
    mScrollSpeed(0.f),
    mCommandQueue(){
    
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures(){
    mTextures.load(Textures::Eagle, Path_Eagle);
    mTextures.load(Textures::Raptor, Path_Raptor);
    mTextures.load(Textures::Desert, Path_Desert);
}

void World::buildScene(){
    for(std::size_t i = 0; i < LayerCount; ++i){
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer)); // attach the layer into the graph
    }

    setBackground();    
    setAirplanes();
}

void World::setBackground(){
    // Get the Textures::Desert, take the bounded and set it to repeated
    sf::Texture& texture = mTextures.get(Textures::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);
    
    // Link the texture to the spritenode
    std::unique_ptr<SpriteNode> backgroundSprite(
        new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(
        mWorldBounds.left,
        mWorldBounds.top);          // set the position (to fullfill the view)
                                    // because the backgroundsprite did not set the origin so its origin is the top left
    mSceneLayers[Background]
        ->attachChild(std::move(backgroundSprite)); // attach the child for the background
}

void World::setAirplanes(){
    setLeader();
    setEscort(true);
    setEscort(false);   
}

void World::setLeader(){
    std::unique_ptr<Aircraft> leader(
        new Aircraft(Aircraft::Eagle, mTextures));
    mPlayerAircraft = leader.get();
    mPlayerAircraft->setPosition(mSpawnPosition);
    mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
    mSceneLayers[Air]->attachChild(std::move(leader));
}

void World::setEscort(bool isleft){
    int tmp = (isleft)? -1 : 1;
    std::unique_ptr<Aircraft> Escort(
        new Aircraft(Aircraft::Raptor, mTextures));
    Escort->setPosition(tmp * 80, 50);
    mPlayerAircraft->attachChild(std::move(Escort));
}

// updating and draw

void World::draw(){
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt){
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

    sf::Vector2f position = mPlayerAircraft->getPosition();
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();

    if(position.x <= mWorldBounds.left + 150
    || position.x >= mWorldBounds.left + mWorldBounds.width - 150){
        velocity.x = -velocity.x;
        mPlayerAircraft->setVelocity(velocity);
    }

    // Forward commands to the scene graph
    while(!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);

    // Regular update step
    mSceneGraph.update(dt);
}

auto World::getCommandQueue() -> CommandQueue&{
    return mCommandQueue;
}
