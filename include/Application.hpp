#pragma once
#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "Player.hpp"
#include "StringConvert.hpp"
#include "StateIdentifiers.hpp"
// Include all the state
#include "TitleState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"
#include "SettingsState.hpp"

const std::string Path_TitleScreen = "resource/Textures/TitleScreen.png";
const std::string Path_Font = "resource/Sansation.ttf";
const std::string Path_MenuScreen = "resource/Textures/Menu.jpg";
const std::string Path_ButtonNormal = "resource/Textures/ButtonNormal.png";
const std::string Path_ButtonSelected = "resource/Textures/ButtonSelected.png";
const std::string Path_ButtonPressed = "resource/Textures/ButtonPressed.png";

class Application{

    public:
        Application();
        void run();

    public:
        void processInput();
        void update(sf::Time dt);
        void render();
    
    public:
        void updateStatic(sf::Time dt);
        void registerStates();


    private:
        static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
	  	FontHolder				mFonts;
		Player					mPlayer;

		StateStack				mStateStack;

		sf::Text				mStayText;
		sf::Time				mStayUpdateTime;
		std::size_t				mStayNumFrames;
};