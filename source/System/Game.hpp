//
//  Window.hpp
//  RPGE
//
//  Created by Pietro De Domenico on 30/11/21.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <stdint.h>
#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "../Game/Level.hpp"
#include "../Game/Entity.hpp"
#include "../System/Camera.hpp"

namespace rpge {

class Game{
public:
    Game(uint32_t p_width, uint32_t p_height, const std::string& p_name):
    width(p_width),
    height(p_height),
    name(p_name),
    window(sf::VideoMode(800, 600), p_name, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize)
    {};
    
    // Window methods
    void Resize(uint32_t p_width, uint32_t p_height);
    
    // Game methods
    void Run(); // Run level
    void LoadLevel(rpge::Level& p_level);
    bool checkCollision(unsigned int x, unsigned int y);
    
private:
    inline void handleEvents();
    inline void render();
    
public:
    unsigned int cellSize;
    sf::Event event;
    std::vector<sf::View> cameras;
    std::vector<std::shared_ptr<rpge::Entity>> entities;
    std::function<void(Game*)> handleEventsScript;
    std::vector<std::function<void(Game*)>> postEventsScripts;
    //std::vector<std::function<void()>> backgroundScripts;
    
private:
    rpge::TileMap tilemap;
    sf::RenderWindow window;
    uint32_t width;
    uint32_t height;
    std::string name;
    std::vector<std::shared_ptr<sf::Drawable>> renderStack;
    
};

} // namespace rpge
