//
//  Entity.hpp
//  RPGE
//
//  Created by Pietro De Domenico on 30/11/21.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace rpge {

class Entity : public sf::Drawable, public sf::Transformable {
public:
    
    Entity(sf::Sprite p_sprite):
    m_sprite(p_sprite)
    {}
    
    inline float getPositionX()
    {
        return m_PositionX;
    }
    
    inline float getPositionY()
    {
        return m_PositionY;
    }
    
    inline void move(int x, int y)
    {
        m_PositionX += x;
        m_PositionY += y;
        
        m_sprite.setPosition(m_PositionX, m_PositionY);
    }
    
private:
    int m_PositionX = 0;
    int m_PositionY = 0;
    sf::Sprite m_sprite;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(m_sprite);
    }
};

} // namespace rpge

