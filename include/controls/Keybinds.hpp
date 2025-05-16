#include <SFML/Graphics.hpp>

#include "KeyActions.hpp"

class Keybinds
{
private:
    KeyActions action;
    sf::Keyboard key;

public:
    Keybinds(const KeyActions &action, const sf::Keyboard &key);
    ~Keybinds();
};