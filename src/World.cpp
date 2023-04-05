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
    mScrollSpeed(-50.f),
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
    // Init
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
    mPlayerAircraft->setVelocity(0.f, 0.f);
    
    // onCommand
    while(!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    
    // change the velocity
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();
    if(velocity.x != 0.f && velocity.y != 0.f)
        mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));

    mPlayerAircraft->accelerate(0.f, mScrollSpeed); // accelerate according to the ScrollSpeed

    // Regular update step
    mSceneGraph.update(dt);
}

auto World::getCommandQueue() -> CommandQueue&{
    return mCommandQueue;
}

void World::setPosition(){
    sf::FloatRect viewBounds(
        mWorldView.getCenter() - mWorldView.getSize() / 2.f,
        mWorldView.getSize());   
    const float borderDistance = 40.f;

    sf::Vector2f position = mPlayerAircraft->getPosition();
    // bounder the position inside the viewBounds with the borderDistance
    // remember the coordinate according to reverse cartesian (similar to the table)
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);

    // return the position
    mPlayerAircraft->setPosition(position);

}
