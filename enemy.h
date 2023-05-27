#include <SFML/Graphics.hpp>
#include<string.h>
#include <cmath>
using namespace sf;
# include "bomb.h"

class Enemy
{
public:    
    Sprite ensprite;
    Texture entex;
    int staytime;
    float x,y;
    int strength;
    Bomb* bomb;
    bool present;

    virtual void move()
    {}

};    

class Dragon: public Enemy
{
public: 
    Dragon()
    {
        x=225;
        y=0;
        entex.loadFromFile("img/dragon1.png");
        ensprite.setTexture(entex);
        ensprite.setScale(1.45,1.45);
        ensprite.setPosition(x,y);
        strength =1000;
        present = true;
        staytime=30;
        bomb = new Bomb[7] { Bomb("img/fire.png",x+170,y+330,-3,5), Bomb("img/fire.png",x+170,y+330,-2,5), Bomb("img/fire.png",x+170,y+330,-1,5), Bomb("img/fire.png",x+170,y+330,0,5), Bomb("img/fire.png",x+170,y+330,1,5), Bomb("img/fire.png",x+170,y+330,2,5), Bomb("img/fire.png",x+170,y+330,3,5) };
        for ( int i=0; i<7; i++)
        {
            bomb[i].sprite.setScale(0.5,0.5);
        }
    }
};

class Monster: public Enemy
{
public:
    Monster()
    {
        x=0;
        y=0;
        entex.loadFromFile("img/monster1.png");
        ensprite.setTexture(entex);
        ensprite.setScale(0.65,0.65);
        ensprite.setPosition(x,y);
        strength =500;
        present = true;
        staytime=60;
        bomb= new Bomb[3]{Bomb ("img/PNG/Lasers/laserRed05.png",x+110,y+330,0,8) , Bomb ("img/PNG/Lasers/laserRed05.png",x+210,y+330,0,8), Bomb ("img/PNG/Lasers/laserRed05.png",x+310,y+330,0,8)};
        
    }
    
    void move()
    {
        x += 0.25;
        ensprite.setPosition(x,y);
    }
};

class Invador: public Enemy
{
public:
    int fireinterval;
};

class Alpha: public Invador
{
public:
    Alpha(int coor_x=0, int coor_y=0)
    {
        x=coor_x;
        y=coor_y;
        entex.loadFromFile("img/enemy_1.png");
        ensprite.setTexture(entex);
        ensprite.setScale(0.75,0.75);
        ensprite.setPosition(x,y);
        strength =100;
        present = true;
        bomb= new Bomb("img/PNG/Lasers/laserRed01.png",x+45,y+10,0,5);
        bomb->sprite.setScale(0.75,0.75);
        fireinterval=5;
    }
};
class Beta: public Invador
{
public:    
    Beta(int coor_x=0, int coor_y=0)
    {
        x=coor_x;
        y=coor_y;
        entex.loadFromFile("img/enemy_2.png");
        ensprite.setTexture(entex);
        ensprite.setScale(0.75,0.75);
        ensprite.setPosition(x,y);
        strength =100;
        present = true;
        bomb= new Bomb("img/PNG/Lasers/laserRed01.png",x,y,0,6);
        fireinterval=3;
    }
};

class Gamma: public Invador
{
public:
    Gamma(int coor_x=0, int coor_y=0)
    {
        x=coor_x;
        y=coor_y;
        entex.loadFromFile("img/enemy_3.png");
        ensprite.setTexture(entex);
        ensprite.setScale(0.5,0.5);
        ensprite.setPosition(x,y);
        strength =100;
        present = true;
        bomb= new Bomb("img/PNG/Lasers/laserRed01.png",x,y,0,7);
        fireinterval=2;
    }
};