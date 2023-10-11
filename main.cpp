#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shoot 'Em Up");
    window.setFramerateLimit(60);  // Limite le nombre d'images par seconde

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("../player.png")) {
        //std::cout <<"Erreur de chargement de l'image" <<std::endl;
        return 1;  // Quitte le jeu en cas d'erreur de chargement de texture
    }
    sf::Sprite player(playerTexture);
    player.setPosition(400, 500);

    std::vector<sf::RectangleShape> bullets;  // Stocke les projectiles

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0) {
            player.move(-5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x < 800 - player.getGlobalBounds().width) {
            player.move(5, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            sf::RectangleShape bullet(sf::Vector2f(5, 10));
            bullet.setFillColor(sf::Color::Red);
            bullet.setPosition(player.getPosition().x + player.getGlobalBounds().width / 2 - 2.5, player.getPosition().y);
            bullets.push_back(bullet);
        }

        for (size_t i = 0; i < bullets.size(); ++i) {
            bullets[i].move(0, -5);  // Déplace les projectiles vers le haut

            if (bullets[i].getPosition().y < 0) {
                bullets.erase(bullets.begin() + i);  // Supprime les projectiles hors de l'écran
            }
        }

        window.clear(sf::Color::Black);

        // Affiche le vaisseau et les projectiles
        window.draw(player);
        for (const auto& bullet : bullets) {
            window.draw(bullet);
        }

        window.display();
    }

    return 0;
}