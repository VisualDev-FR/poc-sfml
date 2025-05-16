#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main()
{
    // Création de la fenêtre avec une taille de 1920x1080 et un titre
    sf::RenderWindow window({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(256); // Limiter le framerate à 60 FPS

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(400, 100)); // Premier point
    triangle.setPoint(1, sf::Vector2f(300, 400)); // Deuxième point
    triangle.setPoint(2, sf::Vector2f(500, 400)); // Troisième point

    // Création d'un texte à afficher dans la fenêtre
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    { // Vous pouvez mettre un chemin valide vers une police
        std::cerr << "Erreur de chargement de la police." << std::endl;
        return -1;
    }

    float speed = 200.f;
    long totalFrames = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        float fps = 1.0f / deltaTime.asSeconds();

        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Déplacement du cercle avec les touches fléchées
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            triangle.move(-speed * deltaTime.asSeconds(), 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            triangle.move(speed * deltaTime.asSeconds(), 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            triangle.move(0.f, -speed * deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            triangle.move(0.f, speed * deltaTime.asSeconds());
        }

        // Gestion de la couleur de la fenêtre avec les touches 'R', 'G', 'B'
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            window.clear(sf::Color::Red); // Fenêtre rouge
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            window.clear(sf::Color::Green); // Fenêtre verte
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            window.clear(sf::Color::Blue); // Fenêtre bleue
        }
        else
        {
            window.clear(sf::Color::Black); // Fenêtre noire par défaut
        }

        sf::Text text("SFML Project - Press ESC to Quit " + std::to_string(fps) + "fps", font, 30);
        text.setFillColor(sf::Color::White); // Couleur du texte
        text.setPosition(10.f, 10.f);        // Position du texte

        // Affichage du texte
        window.draw(text);

        // Affichage du cercle
        window.draw(triangle);

        // Affichage des changements
        window.display();
    }

    return 0;
}
