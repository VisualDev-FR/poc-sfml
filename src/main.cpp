#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    // Création de la fenêtre avec une taille de 1920x1080 et un titre
    sf::RenderWindow window({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(60); // Limiter le framerate à 60 FPS

    // Création d'une forme (Cercle) qui se déplacera avec les touches directionnelles
    sf::CircleShape circle(50.f);          // Rayon du cercle = 50 pixels
    circle.setFillColor(sf::Color::Green); // Couleur du cercle
    circle.setPosition(800.f, 500.f);      // Position initiale du cercle

    // Création d'un texte à afficher dans la fenêtre
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    { // Vous pouvez mettre un chemin valide vers une police
        std::cerr << "Erreur de chargement de la police." << std::endl;
        return -1;
    }

    sf::Text text("SFML Project - Press ESC to Quit", font, 30);
    text.setFillColor(sf::Color::White); // Couleur du texte
    text.setPosition(10.f, 10.f);        // Position du texte

    // Variables pour contrôler la vitesse du cercle
    float speed = 200.f; // Vitesse de déplacement du cercle (en pixels par seconde)
    sf::Clock clock;     // Pour gérer le temps écoulé

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart(); // Calcul du temps écoulé entre deux frames

        // Gestion des événements
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close(); // Ferme la fenêtre si l'utilisateur clique sur la croix
            }
        }

        // Déplacement du cercle avec les touches fléchées
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            circle.move(-speed * deltaTime.asSeconds(), 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            circle.move(speed * deltaTime.asSeconds(), 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            circle.move(0.f, -speed * deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            circle.move(0.f, speed * deltaTime.asSeconds());
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

        // Affichage du texte
        window.draw(text);

        // Affichage du cercle
        window.draw(circle);

        // Affichage des changements
        window.display();
    }

    return 0;
}
