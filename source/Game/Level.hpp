//
//  Map.hpp
//  RPGE
//
//  Created by Pietro De Domenico on 30/11/21.
//

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

namespace rpge {

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    
    int cellSize;
    std::vector<int> collisionMap;
    unsigned int width;
    unsigned int height;
    
    bool Load(
              const std::string& tileset,
              sf::Vector2u tileSize,
              const int* tiles,
              unsigned int width,
              unsigned int height,
              std::vector<int> p_collisionMap);
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }
    
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

class Level {
public:
    
    TileMap map;
    std::vector<rpge::Entity> entities;
    std::vector<sf::View> cameras;
};

} // namespace rpge
