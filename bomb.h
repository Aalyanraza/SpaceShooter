#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb 
{
public:
    Sprite sprite;
    Texture tex;
    int x,y;
    int dx;
    int dy;
    bool present;

Bomb( string png_path, int coorx, int coory, int delx, int dely)
{
    tex.loadFromFile(png_path);
    sprite.setTexture(tex);
    x=coorx;
    y=coory;
    dx=delx;
    dy=dely;

    sprite.setPosition(x,y);
}
void fall()
{
    x+=dx;
    y+=dy;

    sprite.setPosition(x,y);
}

};