#pragma once
#include <SFML/Graphics.hpp>

namespace Collision {
    bool isCollision(sf::RectangleShape& rect, sf::CircleShape& circle) {
        sf::Vector2f circleCenter = circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());
        float radius = circle.getRadius();

        sf::FloatRect rectBounds = rect.getGlobalBounds();

        float closestX = std::max(rectBounds.left, std::min(circleCenter.x, rectBounds.left + rectBounds.width));
        float closestY = std::max(rectBounds.top, std::min(circleCenter.y, rectBounds.top + rectBounds.height));

        
        float distanceX = circleCenter.x - closestX;
        float distanceY = circleCenter.y - closestY;

        
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
  
} 