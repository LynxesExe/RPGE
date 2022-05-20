//
//  Window.cpp
//  RPGE
//
//  Created by Pietro De Domenico on 30/11/21.
//

#include "Game.hpp"
#include <iostream>

void rpge::Game::Run()
{

    // As even the docs says, setFrameRateLimit might not be ideal
    window.setFramerateLimit(180);
    
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            handleEvents();
        }
        render();
    }
}

void rpge::Game::LoadLevel(rpge::Level& p_level)
{
    tilemap = p_level.map;
    for (rpge::Entity entity : p_level.entities)
    {
        auto entityPtr = std::make_shared<rpge::Entity>(entity);
        this->entities.push_back(entityPtr);
        this->renderStack.push_back(entityPtr);
    }
    for (sf::View camera : p_level.cameras)
    {
        this->cameras.push_back(camera);
    }
}

inline void rpge::Game::handleEvents()
{
    if (event.type == sf::Event::Closed)
        window.close();
    //handleEventsScript(event);
    if (event.type == sf::Event::Resized)
    {
        // This is something that the game dev should do
        // for a lot of reason, customising the camera,
        // enabling multiplayer camers and minimaps and so on
        sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
        cameras.begin()->reset(visibleArea);
        cameras.begin()->setCenter((*entities.begin())->getPositionX() + (tilemap.cellSize / 2),
                                   (*entities.begin())->getPositionY() + (tilemap.cellSize / 2));
        cameras.begin()->zoom(0.3f);
        window.setView(*cameras.begin());
    }
    handleEventsScript(this);
    for (auto &script: postEventsScripts)
    {
        script(this);
    }
}

bool rpge::Game::checkCollision(unsigned int x, unsigned int y)
{
    // Check for out of bounds
    if (x < 0 || x > tilemap.width - 1 || 
        y < 0 || y > tilemap.width - 1)
    {
        return true;
    }

    // Check for collision map
    auto vectorItr = tilemap.collisionMap.begin() + x + y * tilemap.width;
    if (vectorItr < tilemap.collisionMap.begin() ||
        vectorItr > tilemap.collisionMap.end() ||
        *vectorItr)
    {
        return true;
    }
    return false;
}

inline void rpge::Game::render()
{
    window.clear(sf::Color::Black);
    // For each camera, draw everything
    // This method is flawed, not all the time the view needs to render everything
    // For example, minimap do not need to render UI
    for (sf::View camera : cameras)
    {
        window.setView(camera);
        window.draw(tilemap);
        for (std::shared_ptr<sf::Drawable> object : renderStack)
        {
            window.draw(*object);
        }
    }
    window.display();
}
