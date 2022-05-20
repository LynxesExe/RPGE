
#include "System/Game.hpp"
#include "Game/Level.hpp"
#include "Game/Entity.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>

#include <iostream>


int main()
{

    // Composing map
    rpge::TileMap map;
    map.cellSize = 16;
    const int mapTiles[] =
    {
        3, 11, 12, 13, 3,
        3, 30, 31, 32, 3,
        3, 49, 50, 51, 3,
        3, 3, 3, 3, 3,
        3, 3, 3, 3, 3
    };
    std::vector<int> collisionMap =
    {
        0, 1, 1, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    map.Load("../resources/assets/sprites.png", sf::Vector2u(16, 16), mapTiles, 5, 5, collisionMap);
    
    // Creating sprite
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../resources/assets/sprites.png", sf::IntRect(128, 224, 16, 16));
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(0, 0);
    rpge::Entity player(playerSprite);
    
    
    // Creating cameras
    // Main camera
    sf::View camera;
    sf::FloatRect viewArea(0.f, 0.f, 800.f, 600.f);
    camera.reset(viewArea);
    camera.setCenter(playerSprite.getOrigin().x + 8.f, playerSprite.getOrigin().y + 8.f);
    camera.zoom(0.3f);
    camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    // Minimap
    sf::View miniMap;
    sf::FloatRect miniViewArea(0.f, 0.f, -800.f, -600.f);
    miniMap.reset(miniViewArea);
    miniMap.setCenter(0, 0);
    miniMap.zoom(-0.5f);
    miniMap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
    
    
    
    // Composing level
    rpge::Level level;
    level.map = map;
    level.cameras.push_back(camera);
    level.cameras.push_back(miniMap);
    level.entities.push_back(player);
    
    
    rpge::Game window(800, 600, "RPGEngine");
    window.LoadLevel(level);
    
    // Creating scripts
    // Handling user input
    auto keyDelay = std::chrono::high_resolution_clock::now();
    window.handleEventsScript = [keyDelay](rpge::Game* game){
        if (game->event.type == sf::Event::KeyPressed)
        {
            if (std::chrono::time_point_cast<std::chrono::milliseconds>(keyDelay).time_since_epoch().count() < 2000)
            {
                return;
            }
            switch (game->event.key.code) {
                case sf::Keyboard::W:
                    if (!game->checkCollision((*game->entities.begin())->getPositionX() / 16,
                                        ((*game->entities.begin())->getPositionY() - 16) / 16))
                    {
                        (*game->entities.begin())->move(0, -16);
                        game->cameras.begin()->move(0, -16);
                    }
                    break;
                case sf::Keyboard::S:
                    if (!game->checkCollision((*game->entities.begin())->getPositionX() / 16,
                                        ((*game->entities.begin())->getPositionY() + 16) / 16))
                    {
                        (*game->entities.begin())->move(0, 16);
                        game->cameras.begin()->move(0, 16);
                    }
                    break;
                case sf::Keyboard::A:
                    if (!game->checkCollision(((*game->entities.begin())->getPositionX() - 16) / 16,
                                        (*game->entities.begin())->getPositionY() / 16))
                    {
                        (*game->entities.begin())->move(-16, 0);
                        game->cameras.begin()->move(-16, 0);
                    }
                    break;
                case sf::Keyboard::D:
                    if (!game->checkCollision(((*game->entities.begin())->getPositionX() + 16) / 16,
                                        (*game->entities.begin())->getPositionY() / 16))
                    {
                        (*game->entities.begin())->move(16, 0);
                        game->cameras.begin()->move(16, 0);
                    }
                    break;
                case sf::Keyboard::Space:
                    
                    break;
                default:
                    break;
            }
        }
    };
    
    
//    window.postEventsScripts.push_back([](rpge::Game *game) {
//        std::cout << "RUNNING SCRIPT :D" << std::endl;
//    });
    
    window.Run(); //blocking method

    return 0;
}
