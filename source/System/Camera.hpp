//
//  Camera.hpp
//  RPGE
//
//  Created by Pietro De Domenico on 01/12/21.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace rpge {

class Camera {
public:
    
    Camera(sf::View p_view):
    m_view(p_view)
    {}
    
    inline sf::View getView()
    {
        return m_view;
    }
    
private:
    sf::View m_view;
};

} // namespace rpge
