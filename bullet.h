#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{

public:
    Texture bultex; 
    Texture bulrighttex; 
    Texture bullefttex; 
    Sprite bulsprite;
    int coor_x, coor_y;
    int speed_dx, speed_dy;
    bool active;

Bullet()
{

    bultex.loadFromFile("img/PNG/Effects/fire07.png");
    bullefttex.loadFromFile("img/PNG/Effects/leftbul.png");
    bulrighttex.loadFromFile("img/PNG/Effects/rightbul.png");
    bulsprite.setTexture(bultex);
    bulsprite.setScale(1, 1);
    speed_dx = 0;
    speed_dy = -5;
    active=0;
}

void move()
{

    coor_x += speed_dx ;
    coor_y += speed_dy ;
    bulsprite.setPosition(coor_x, coor_y);
}



~Bullet()
{
    active=0;
}
};
