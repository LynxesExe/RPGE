//
//  Map.cpp
//  RPGE
//
//  Created by Pietro De Domenico on 30/11/21.
//

#include "Level.hpp"

bool rpge::TileMap::Load(const std::string& tileset,
                         sf::Vector2u tileSize,
                         const int* tiles,
                         unsigned int p_width,
                         unsigned int p_height,
                         std::vector<int> p_collisionMap)
{
    if (!m_tileset.loadFromFile(tileset))
    {
        return false;
    }
    
    // Apply collision map
    collisionMap = p_collisionMap;
    
    // Record width and height
    width = p_width;
    height = p_height;
    
    // Resize VertexArray to accomodate level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(p_width * p_height * 4);
    
    // Populate VertexArray with one quad per tile
    for (unsigned int i = 0; i < p_width; ++i)
    {
        for (unsigned int j = 0; j < p_height; ++j)
        {
            
            int tileNumber = tiles[i + j * p_width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            
            
        }
    }
    
}
