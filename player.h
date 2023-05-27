# ifndef player_h
# define player_h


# include <SFML/Graphics.hpp>
# include <string.h>
# include <cmath>
# include "bullet.h"
# include "Addons.h"
using namespace sf;

class Player
{

public:
	Texture tex;
	Texture texur;
	Texture texul;
	Sprite sprite;
    Sprite lifesprite;
	float speed=2;
	int x,y;
	int lifes;
	int strength;
    Bullet* b;
    Addons* adds;
    int power;
    int numbul;
    bool candie;

Player(std::string png_path)
{

	tex.loadFromFile(png_path);
	texur.loadFromFile("img/right.png");
	texul.loadFromFile("img/left.png");
	
	sprite.setTexture(tex);
    lifesprite.setTexture(tex);
    lifesprite.setScale(.25,.25);
    sprite.setScale(0.65,0.65);
	x=340;y=675;
	sprite.setPosition(x,y);
	sprite.setScale(1,1);
	lifes=3;
    int power=0;
	strength=100;
    b = new Bullet[100];
    numbul=0;
    adds=nullptr;
    candie=0;
}
void fire(int f)
{
    if (power==1)
    {
        b[numbul]. bultex.loadFromFile("img/fire.png");
        b[numbul]. bullefttex.loadFromFile("img/fire.png");
        b[numbul]. bulrighttex.loadFromFile("img/fire.png");
        b[numbul]. bulsprite.setTexture( b[numbul]. bultex );
    }
    b[numbul].active=1;
    numbul++;
    
    if (f==1)
    {
        b[numbul].speed_dx=0;
        b[numbul].coor_x=x+45;
        b[numbul].coor_y=y-20;
        b[numbul].bulsprite.setTexture(b[numbul].bultex);
        b[numbul].bulsprite.setScale(1,1);
    }
    else if (f==0)
    {
        b[numbul].speed_dx=-5;
        b[numbul].coor_x=x-20;
        b[numbul].coor_y=y-20;
        b[numbul].bulsprite.setTexture(b[numbul].bullefttex);
        b[numbul].bulsprite.setScale(1.5,1.5);
    }
    else if (f==2)
    {
        b[numbul].speed_dx=5;        
        b[numbul].coor_x=x+120;
        b[numbul].coor_y=y-20;
        b[numbul].bulsprite.setTexture(b[numbul].bulrighttex);
        b[numbul].bulsprite.setScale(1.5,1.5);
    }
    
}
void move(std::string s)
{
    float delta_x = 0, delta_y = 0;
    if (s == "ur")                      //Up-Right
    {
        delta_x = 1;
        delta_y = -1;
        sprite.setScale(1.4,1.4);
        sprite.setTexture(texur);
    }
    else if (s == "ul")                 //Up-Left
    {
        delta_x = -1;
        delta_y = -1;
        sprite.setScale(1.4,1.4);
        sprite.setTexture(texul);
    }
    else if (s == "dr")                 //Down-Right
    {
        delta_x = 1;
        delta_y = 1;
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }
    else if (s == "dl")                 //Down-Right
    {
        delta_x = -1;
        delta_y = 1;		
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }
    else if (s == "l")                  //Left
    {
        delta_x = -1;
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }
    else if (s == "r")                  //Right
    {
        delta_x = 1;
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }
    else if (s == "u")                  //Up
    {
        delta_y = -1;
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }
    else if (s == "d")                  //Down
    {
        delta_y = 1;
        sprite.setScale(1,1);
		sprite.setTexture(tex);
    }

    delta_x *= speed;
    delta_y *= speed;

    // check if spaceship goes beyond horizontal screen boundaries
    if (x + delta_x > 780)
    {
        x = 0;
    }
    else if (x + delta_x < 0)
    {
        x = 780;
    }
    else
    {
        x += delta_x;
    }

    // check if spaceship stays within vertical boundaries
    if (y + delta_y > 0 && y + delta_y < 675)
    {
        y += delta_y;
    }

    // set the new position of the sprite
    sprite.setPosition(x, y);
}

};

#endif