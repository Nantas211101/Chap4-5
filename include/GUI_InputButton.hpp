#pragma once
#include <SFML/Graphics.hpp>

#include "GUI_Component.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureManipulate.hpp"

#include <assert.h>
#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace GUI {

class InputButton : public Component {
  public:
    typedef std::shared_ptr<InputButton> Ptr;
    typedef std::function<void()> Callback;

  public:
    InputButton(const FontHolder& fonts, const TextureHolder& textures);

    void setCallback(Callback callback);
    void setText(const std::string& text);
    void setToggle(bool flag);
    virtual std::string takeSaveText();

    // selection
    virtual bool isSelectable() const;
    virtual void select();
    virtual void deselect();

    // Activation
    virtual void activate();
    virtual void deactivate();

    virtual void handleEvent(const sf::Event& event);
    virtual bool handleRealTimeInput(const sf::RenderWindow& window);
    virtual bool isSpeedButton();
    virtual bool isSpeedUp();

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    auto takeLocalBounds() -> sf::FloatRect;
    bool contain(sf::Vector2i pos, sf::FloatRect rec);

  private:
    Callback mCallback;
    const sf::Texture& mNormalTexture;
    const sf::Texture& mSelectedTexture;
    const sf::Texture& mPressedTexture;
    sf::Sprite mSprite;
    sf::Text mText;
    bool mIsToggle;
    std::string saveText;
};

} // namespace GUI

namespace inputID {
enum ID {
    Pos,
    Val,
};
}