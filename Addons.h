# ifndef addons_h
# define addons_h
# include "player.h"

class Addons
{
public:    
    Sprite sprite;
    Texture tex;
    int x,y;
    
}; 
class Danger: public Addons
{
public:
    Danger( int coor_x=100, int coor_y=350)
    {
        tex.loadFromFile("img/PNG/Power-ups/pill_red.png");
        sprite.setTexture(tex);
        x=coor_x;
        y=coor_y;
        sprite.setPosition (x,y);
    }
    
};
class Life: public Addons
{
public:    
    Life( int coor_x=100, int coor_y=350)
    {
        tex.loadFromFile("img/PNG/Power-ups/bolt_silver.png");
        sprite.setTexture(tex);
        x=coor_x;
        y=coor_y;
        sprite.setPosition (x,y);
    }
    
};
class Fire: public Addons
{
public:    
    Fire( int coor_x=100, int coor_y=350)
    {
        tex.loadFromFile("img/PNG/Power-ups/bolt_bronze.png");
        sprite.setTexture(tex);
        x=coor_x;
        y=coor_y;
        sprite.setPosition (x,y);
    }
    
};
class Power_up: public Addons
{
public:    
    Power_up( int coor_x=100, int coor_y=350)
    {
        tex.loadFromFile("img/PNG/Power-ups/bolt_gold.png");
        sprite.setTexture(tex);
        x=coor_x;
        y=coor_y;
        sprite.setPosition (x,y);
    }
    
};



#endif