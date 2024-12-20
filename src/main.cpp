#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(60);

    // Création d'une forme (Cercle) qui se déplacera avec les touches directionnelles
    sf::CircleShape circle(50.f);          // Rayon du cercle = 50 pixels
    circle.setFillColor(sf::Color::Blue); // Couleur du cercle
    circle.setPosition(800.f, 500.f);      // Position initiale du cercle

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
}
