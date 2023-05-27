
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include<string>
using namespace std;
#include "player.h"
#include "enemy.h"
#include "levels.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

void pause()
{
    bool flag=1;
    cout<<1;
    while (flag)
    {
        if (Keyboard::isKeyPressed(Keyboard::B))
            flag=0;
    }
}

class Game
{
public:
    Sprite background; //Game background sprite
    Texture bg_texture;
    Text text;
    Text text2;
    Font font;
    Player* p; //player 
    Enemy* attack;
    Level1 l1;
    Level2 l2;
    Level3 l3;
    int level; 
    int score;
    bool gameover;
    
// add other game attributes


Game()
{
    p=new Player("img/player_ship.png");
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(2, 1.5);
    level=1;
    score=0;
    attack=nullptr;
    gameover=0;
    font.loadFromFile("img/arial.ttf");
    
    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setFillColor( Color:: White);
    
}

void start_game( RenderWindow& window)
{
    srand(time(0));
    Clock clock;
    float shipattack=0, enemytimer=0, bombtimer=0, addtimer=0, pausetimer=0, dietimer=0, powertimer=0 ;
    float timer=0;
    int direct=1;
    int addnum=0;
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        shipattack+=time;
        enemytimer+=time;
        bombtimer +=time;
        addtimer += time;
        dietimer += time;
        pausetimer += time;
        powertimer += time;
        clock.restart();
        timer += time;  
        
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed)    // If cross/close is clicked/pressed
            {
                cout<<"Score: "<<score<<endl;
                window.close();             //close the game                        	    
            }
        }
	if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) //If up key is pressed
    {   
        p->move("ul");    //playet will move upwards
        direct=0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard:: Right)) // If down key is pressed
    {
        p->move("ur");  //player will move downwards            
        direct=2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)) //If up key is pressed
    {   
        p->move("dl");    //playet will move upwards
        direct=1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard:: Right)) // If down key is pressed
    {   
        p->move("dr");    //playet will move upwards
        direct=1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
    {   
        p->move("l");    //playet will move upwards
        direct=1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
    {   
        p->move("r");    //playet will move upwards
        direct=1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
    {   
        p->move("u");    //playet will move upwards
        direct=1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
    {   
        p->move("d");    //playet will move upwards
        direct=1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        if (shipattack>0.1)
        {
            p->fire(direct);
            shipattack=0;
        }
    }    
    if (Keyboard::isKeyPressed(Keyboard:: P))
    {
        pause();
    }
    
    
    ////////////////////////////////////////////////
	/////  Call your functions here            ////
    
    if (dietimer >3 && dietimer<3.5)
        p->candie=1;

    if ( p->lifes<0 || gameover)
    {
        fstream file("file.txt");
        file<<score<<endl;

        file.close();
        cout<<"I'm here\n";
        return;
    }
    // PLAYER FUNCTIONS    
    for (int i=0;  i<p->numbul; i++)        //Bullet Movement
    {
        if (p->b[i].active)
            p->b[i].move();
    }
	if (p->numbul==100)                     //Reload
    {
        p->numbul=0;
    }
    for (int i=0;  i<p->numbul; i++)        //Out of Bounds
    {
        if (p->b[i].coor_y==0)
        {
            p->b[i].active=0;
        }
    }    
    
    //ENEMY FUNCTIONS

    // Levels
    if (level == 1  && !(l1.check1==1 || l1.check2==1 || l1.check3==1 || l1.monbool==1 || l1.dragbool==1)) 
    {
        bool spawned = false;
        while (!spawned) 
        {
            int x = rand() % 5;
            if (x == 0 && l1.check1 == 0) 
            {
                l1.check1 = 1;
                cout<<"Wave 1 produced...\n";
                l1.wave1(attack);
                spawned = true;
            } 
            else if (x == 1 && l1.check2 == 0) 
            {
                l1.check2 = 1;
                cout<<"Wave 2 produced...\n";
                l1.wave2(attack);
                spawned = true;
            } 
            else if (x == 2 && l1.check3 == 0) 
            {
                l1.check3 = 1;
                cout<<"Wave 3 produced...\n";
                l1.wave3(attack);
                spawned = true;
            } 
            else if (x == 3 && l1.monbool == 0) 
            {
                l1.monbool = 1;
                cout<<"Monster produced...\n";
                l1.monster(attack);
                spawned = true;
            }
            else if (x == 4 && l1.dragbool == 0) 
            {
                l1.dragbool = 1;
                cout<<"Monster produced...\n";
                l1.dragon(attack);
                spawned = true;
            } 
            else if (l1.check1 == 2 && l1.check2 == 2 && l1.check3 == 2 && l1.dragbool == 2 && l1.monbool == 2) 
            {
                cout<<"LEvelled Up...\n";
                spawned = true;
                level = 2;
            }
        }
    }
    else if (level == 2 && !(l2.check1 == 1 || l2.check2 == 1 || l2.check3 == 1 || l2.monbool == 1 || l2.dragbool == 1)) 
    {
        bool spawned = false;
        while (!spawned) 
        {
            int x = rand() % 5;
            if (x == 0 && l2.check1 == 0) 
            {
                l2.check1 = 1;
                cout<<"Wave 1 produced...\n";
                l2.wave1(attack);
                spawned = true;
            } 
            else if (x == 1 && l2.check2 == 0) 
            {
                l2.check2 = 1;
                cout<<"Wave 2 produced...\n";
                l2.wave2(attack);
                spawned = true;
            } 
            else if (x == 2 && l2.check3 == 0) 
            {
                l2.check3 = 1;
                cout<<"Wave 3 produced...\n";
                l2.wave3(attack);
                spawned = true;
            } 
            else if (x == 3 && l2.monbool == 0) 
            {
                l2.monbool = 1;
                cout<<"Monster produced...\n";
                l2.monster(attack);
                spawned = true;
            }
            else if (x == 4 && l2.dragbool == 0) 
            {
                l2.dragbool = 1;
                cout<<"Dragon produced...\n";
                l2.dragon(attack);
                spawned = true;
            } 
            else if (l2.check1 == 2 && l2.check2 == 2 && l2.check3 == 2 && l2.dragbool == 2 && l2.monbool == 2) 
            {
                cout<<"Levlled Up...\n";
                spawned = true;
                level = 3;
            }
        }
    }
    else if (level == 3 && !(l3.check1 == 1 || l3.check2 == 1 || l3.check3 == 1 || l3.monbool == 1 || l3.dragbool == 1 || l3.check4 == 1 || l3.check5 == 1 || l3.check6 == 1)) 
    {
        bool spawned = false;
        while (!spawned) 
        {
            int x = rand() % 8;
            if (x == 0 && l3.check1 == 0) 
            {
                l3.check1 = 1;
                cout<<"Wave 1 produced...\n";
                l3.wave1(attack);
                spawned = true;
            } 
            else if (x == 1 && l3.check2 == 0) 
            {
                l3.check2 = 1;
                cout<<"Wave 2 produced...\n";
                l3.wave2(attack);
                spawned = true;
            } 
            else if (x == 2 && l3.check3 == 0) 
            {
                l3.check3 = 1;
                cout<<"Wave 3 produced...\n";
                l3.wave3(attack);
                spawned = true;
            } 
            else if (x == 3 && l3.monbool == 0) 
            {
                l3.monbool = 1;
                cout<<"Monster produced...\n";
                l3.monster(attack);
                spawned = true;
            }
            else if (x == 4 && l3.dragbool == 0) 
            {
                l3.dragbool = 1;
                cout<<"Dragon produced...\n";
                l3.dragon(attack);
                spawned = true;
            }
            else if (x == 5 && l3.check4 == 0) 
            {
                l3.check4 = 1;
                cout<<"Wave 4 produced...\n";
                l3.wave4(attack);
                spawned = true;
            }
            else if (x == 6 && l3.check5 == 0) 
            {
                l3.check5 = 1;
                cout<<"Wave 5 produced...\n";
                l3.wave5(attack);
                spawned = true;
            }
            else if (x == 7 && l3.check6 == 0) 
            {
                l3.check6 = 1;
                cout<<"Wave 6 produced...\n";
                l3.wave6(attack);
                spawned=true;
            }
            else if (l3.check1 == 2 && l3.check2 == 2 && l3.check3 == 2 && l3.dragbool == 2 && l3.monbool == 2 && l3.check4==2 && l3.check5==2 && l3.check6==2) 
            {
                cout<<"Putting gameover!!!!\n";
                spawned = true;
                gameover=1; 
            }
        }
    }    
    
    // Bomb Falling
    if (attack!=nullptr)
    {
        if (level==1)
        {
            
            int x;
            if (l1.check1==1 )
            {
                for (int i = 0; i < 10; i++) 
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if (bombtimer > 5 && x==1) 
                    {
                        attack[i].bomb->x = attack[i].x + 43;
                        attack[i].bomb->y = attack[i].y + 40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x, attack[i].bomb->y);
                    }
                }
            }
            else if (l1.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if ( bombtimer>5 && x==1 )
                    {
                        attack[i].bomb->x=l1.coordinates[i][0]+43;
                        attack[i].bomb->y=l1.coordinates[i][1]+40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
                    }
                }         
            }
            else if (l1.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if ( bombtimer>5 && x==1 )
                    {
                        attack[i].bomb->x=l1.coordinates[i][0]+43;
                        attack[i].bomb->y=l1.coordinates[i][1]+40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
                    }
                }                        
            }
            else if (l1.monbool==1 )
            {
                attack->move();
                for (int i=0; i<3; i++)
                {
                    attack->bomb[i].fall();
                    if (bombtimer>3)
                    {
                        attack->bomb[0].x=attack->x+210;
                        attack->bomb[1].x=attack->x+110;
                        attack->bomb[2].x=attack->x+310;
                        attack->bomb[i].y=attack->y+330;
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
                if (bombtimer>3)
                    bombtimer=0;
            }
            else if (l1.dragbool==1)
            {    
                for (int i=0; i<7; i++)
                {
                    attack->bomb[i].fall();   
                    if (bombtimer>5)
                    {
                        attack->bomb[i].x=attack->x+170;
                        attack->bomb[i].y=attack->y+330;  
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
            }
            if (bombtimer>5)
                bombtimer=0;
                    
        }
        else if (level==2)
        {
            int x;
            if (l2.check1==1 || l2.check2==1 || l2.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if (bombtimer > 3 && x==1) 
                    {
                        attack[i].bomb->x = attack[i].x + 43;
                        attack[i].bomb->y = attack[i].y + 40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x, attack[i].bomb->y);
                    }
                }
            }
            else if (l2.monbool==1 )
            {
                attack->move();
                for (int i=0; i<3; i++)
                {
                    attack->bomb[i].fall();
                    if (bombtimer>3)
                    {
                        attack->bomb[0].x=attack->x+210;
                        attack->bomb[1].x=attack->x+110;
                        attack->bomb[2].x=attack->x+310;
                        attack->bomb[i].y=attack->y+330;
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
            }
            else if (l2.dragbool==1)
            {    
                for (int i=0; i<7; i++)
                {
                    attack->bomb[i].fall();   
                    if (bombtimer>3)
                    {
                        attack->bomb[i].x=attack->x+170;
                        attack->bomb[i].y=attack->y+330;  
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
            }
            if (bombtimer>3)
                    bombtimer=0;
        }
        else if (level==3)
        {
            int x;
            if (l3.check1==1)
            {
                for (int i=0; i<10; i++)
                {
                    x=rand()%2;  
                    attack[i].bomb->fall();
                    if (bombtimer > 2 && x==1) 
                    {
                        attack[i].bomb->x = attack[i].x + 43;
                        attack[i].bomb->y = attack[i].y + 40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x, attack[i].bomb->y);
                    }
                }
            }
            else if (l3.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if (bombtimer > 2 && x==1) 
                    {
                        attack[i].bomb->x = attack[i].x + 43;
                        attack[i].bomb->y = attack[i].y + 40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x, attack[i].bomb->y);
                    }
                }       
            }
            else if (l3.check3==1 || l3.check4==1 || l3.check5==1 || l3.check6==1)
            {
                for (int i=0; i<12; i++)
                {
                    x=rand()%2;
                    attack[i].bomb->fall();
                    if (bombtimer > 2 && x==1) 
                    {
                        attack[i].bomb->x = attack[i].x + 43;
                        attack[i].bomb->y = attack[i].y + 40;
                        attack[i].bomb->sprite.setPosition(attack[i].bomb->x, attack[i].bomb->y);
                    }
                }                      
            }
            else if (l3.monbool==1 )
            {
                attack->move();
                for (int i=0; i<3; i++)
                {
                    attack->bomb[i].fall();
                    if (bombtimer>2)
                    {
                        attack->bomb[0].x=attack->x+210;
                        attack->bomb[1].x=attack->x+110;
                        attack->bomb[2].x=attack->x+310;
                        attack->bomb[i].y=attack->y+330;
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
            }
            else if (l3.dragbool==1)    
            {    
                for (int i=0; i<7; i++)
                {
                    attack->bomb[i].fall();   
                    if (bombtimer>2)
                    {
                        attack->bomb[i].x=attack->x+170;
                        attack->bomb[i].y=attack->y+330;  
                        attack->bomb[i].sprite.setPosition(attack->bomb[i].x,attack->bomb[i].y);
                    }
                }
            }
            if (bombtimer>2)
                bombtimer=0;
        }      
    }    
    
    //Collision 
    
    // Spaceship Bullet Collision
    if (level==1)
    {
        if  (l1.check1==1)
        {
            for (int i=0; i<10; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if ( p->b[j].coor_x> bounds.left && p->b[j].coor_x< bounds.left+bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height)
                            {
                                if (p->power!=1)
                                    p->b[j].active=0;
                                attack[i].present=0;
                                score+=100;
                            }    
                    }
                }
            }    
        }
        else if (l1.check2==1)
        {
            for (int i=0; i<9; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if ( p->b[j].coor_x> bounds.left && p->b[j].coor_x< bounds.left+bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height)
                            {
                                if (p->power!=1)
                                    p->b[j].active=0;
                                attack[i].present=0;
                                score+=100;
                            }    
                    }
                }
            }
        }
        else if (l1.check3==1)
        {
            for (int i=0; i<12; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if (p->b[j].coor_x > bounds.left && p->b[j].coor_x < bounds.left + bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height && p->b[j].coor_x > 0 && p->b[j].coor_x < 780 && p->b[j].coor_y > 0 && p->b[j].coor_y < 780)
                            {
                                if (p->power!=1)
                                    p->b[j].active = 0;
                                attack[i].present = 0;
                                score+=100;
                            }
                    }
                }
            }
        }
        else if (l1.dragbool==1 || l1.monbool==1)
        {
           if (attack->present)
            {
                FloatRect bounds= attack->ensprite.getGlobalBounds();
                for (int j=0; j<p->numbul; j++)
                {
                    if (p->b[j].active)
                        if (p->b[j].coor_x > bounds.left && p->b[j].coor_x < bounds.left + bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height && p->b[j].coor_x > 0 && p->b[j].coor_x < 780 && p->b[j].coor_y > 0 && p->b[j].coor_y < 780)
                        {
                            if (p->power!=1)
                                p->b[j].active = 0;
                            attack->strength -=10;
                            score+=100;
                        }
                }
                if (attack->strength<=0)
                {
                    attack->present=0;
                }
            } 
        }
    }    
    else if (level==2)
    {
        if  (l2.check1==1 || l2.check2==1 || l2.check3==1)
        {
            for (int i=0; i<12; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if ( p->b[j].coor_x> bounds.left && p->b[j].coor_x< bounds.left+bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height)
                            {
                                if (p->power!=1)
                                    p->b[j].active=0;
                                attack[i].present=0;
                                score+=200;
                            }    
                    }
                }
            }
        }
        else if (l2.dragbool==1 || l2.monbool==1)
        {
           if (attack->present)
            {
                FloatRect bounds= attack->ensprite.getGlobalBounds();
                for (int j=0; j<p->numbul; j++)
                {
                    if (p->b[j].active)
                        if (p->b[j].coor_x > bounds.left && p->b[j].coor_x < bounds.left + bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height && p->b[j].coor_x > 0 && p->b[j].coor_x < 780 && p->b[j].coor_y > 0 && p->b[j].coor_y < 780)
                        {
                            if (p->power!=1)
                                p->b[j].active = 0;
                            attack->strength -=10;
                        }
                }
                if (attack->strength<=0)
                {
                    attack->present=0;
                }
            } 
        }
    }
    else if (level==3)
    {
    
        if  (l3.check1==1)
        {
            for (int i=0; i<10; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if ( p->b[j].coor_x> bounds.left && p->b[j].coor_x< bounds.left+bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height)
                            {
                                if (p->power!=1)
                                    p->b[j].active=0;
                                attack[i].present=0;
                                score+=300;
                            }    
                    }
                }
            }    
        }
        else if (l3.check2==1)
        {
            for (int i=0; i<9; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if ( p->b[j].coor_x> bounds.left && p->b[j].coor_x< bounds.left+bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height)
                            {
                                if (p->power!=1)
                                    p->b[j].active=0;
                                attack[i].present=0;
                                score+=300;
                            }    
                    }
                }
            }
        }
        else if (l3.check3==1 || l3.check4==1 || l3.check5==1 || l3.check6==1)
        {
            for (int i=0; i<12; i++)
            {
                if (attack[i].present)
                {
                    FloatRect bounds= attack[i].ensprite.getGlobalBounds();
                    for (int j=0; j<p->numbul; j++)
                    {
                        if (p->b[j].active)
                            if (p->b[j].coor_x > bounds.left && p->b[j].coor_x < bounds.left + bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height && p->b[j].coor_x > 0 && p->b[j].coor_x < 780 && p->b[j].coor_y > 0 && p->b[j].coor_y < 780)
                            {
                                if (p->power!=1)
                                    p->b[j].active = 0;
                                attack[i].present = 0;
                                score+=300;
                            }
                    }
                }
            }
        }
        else if (l3.dragbool==1 || l3.monbool==1)
        {
           if (attack->present)
            {
                FloatRect bounds= attack->ensprite.getGlobalBounds();
                for (int j=0; j<p->numbul; j++)
                {
                    if (p->b[j].active)
                        if (p->b[j].coor_x > bounds.left && p->b[j].coor_x < bounds.left + bounds.width && p->b[j].coor_y > bounds.top && p->b[j].coor_y < bounds.top + bounds.height && p->b[j].coor_x > 0 && p->b[j].coor_x < 780 && p->b[j].coor_y > 0 && p->b[j].coor_y < 780)
                        {
                            if (p->power!=1)
                                p->b[j].active = 0;
                            attack->strength -=10;
                        }
                }
                if (attack->strength<=0)
                {
                    attack->present=0;
                }
            } 
        }
    }
    
    // Spaceship Collision (with enemy or their bullets) 
    if (p->candie)
    {
        if (level==1)
        {
            FloatRect shipbounds = p->sprite.getGlobalBounds();
            if (l1.check1==1)
            {
                for (int i=0; i<10; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        
                    }
                }
            }
            else if (l1.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        
                    }
                }
            }
            else if (l1.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        { 
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        
                    }
                }
            }
            else if ( l1.monbool==1 )
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();  
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {    
                        if (p->lifes > 0)
                        {
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                    for (int i=0; i<3; i++) 
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {  
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = enemybounds.left+360;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }    
            }
            else if ( l1.dragbool==1)
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();  
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {    
                        // Print the player's remaining life count.
                        cout <<"Lives:"<< --(p->lifes) <<endl;
                        dietimer=0;
                        p->candie=0;
                        // Respawn the player's ship at the default location.
                        p->x = 0;
                        p->y = 675;
                        p->sprite.setPosition(p->x, p->y);
                    }
                    for (int i=0; i<7; i++)
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;

                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }    
            }      
        }
        else if (level==2) 
        {
            FloatRect shipbounds = p->sprite.getGlobalBounds();
            if ( l2.check1==1 || l2.check2==1|| l2.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }
            }
            else if ( l2.monbool==1 )
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();   
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {   
                        // Print the player's remaining life count.
                        cout <<"Lives:"<< --(p->lifes) <<endl;
                        dietimer=0;
                        p->candie=0;
                        // Respawn the player's ship at the default location.
                        p->x = 0;
                        p->y = 675;
                        p->sprite.setPosition(p->x, p->y);
                    }
                    for (int i=0; i<3; i++) 
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {   
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }    
            }
            else if ( l2.dragbool==1)
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();  
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {    
                        // Print the player's remaining life count.
                        cout <<"Lives:"<< --(p->lifes) <<endl;
                        dietimer=0;
                        p->candie=0;

                        // Respawn the player's ship at the default location.
                        p->x = 0;
                        p->y = 675;
                        p->sprite.setPosition(p->x, p->y);
                    }
                    for (int i=0; i<7; i++)
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }    
            }
          
        }
        else if (level==3)   
        {
            FloatRect shipbounds = p->sprite.getGlobalBounds();
            if (l3.check1==1)
            {
                for (int i=0; i<10; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds();
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
    
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {                
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }
            }
            else if ( l3.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds();
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;\
                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        }
                    }
                }
            }
            else if ( l3.check3==1 || l3.check4==1 || l3.check5==1|| l3.check6==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        FloatRect enemybounds = attack[i].ensprite.getGlobalBounds();  
                        FloatRect bombbounds = attack[i].bomb->sprite.getGlobalBounds();
                        if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                                // Print the player's remaining life count.
                                cout <<"Lives:"<< --(p->lifes) <<endl;
                                dietimer=0;
                                p->candie=0;

                                // Respawn the player's ship at the default location.
                                p->x = 340;
                                p->y = 675;
                                p->sprite.setPosition(p->x, p->y);
                            
                        }
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
    
                    }
                    }
                }
            }
            else if ( l3.monbool==1 )
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();  
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 0;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                        
                    }
                    for (int i=0; i<3; i++)
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
                            
                        }
                    }
                }   
            }
            else if ( l3.dragbool==1)
            {    
                if (attack->present)
                {
                    FloatRect enemybounds = attack->ensprite.getGlobalBounds();  
                    if (shipbounds.left + shipbounds.width >= enemybounds.left && shipbounds.left <= enemybounds.left + enemybounds.width &&  shipbounds.top + shipbounds.height >= enemybounds.top && shipbounds.top <= enemybounds.top + enemybounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                    {   
                        // Print the player's remaining life count.
                        cout <<"Lives:"<< --(p->lifes) <<endl;

                        // Respawn the player's ship at the default location.
                        p->x = 0;
                        p->y = 675;
                        p->sprite.setPosition(p->x, p->y);
                    }
                    for (int i=0; i<7; i++)
                    {
                        FloatRect bombbounds = attack->bomb[i].sprite.getGlobalBounds(); 
                        if (shipbounds.left + shipbounds.width >= bombbounds.left && shipbounds.left <= bombbounds.left + bombbounds.width &&  shipbounds.top + shipbounds.height >= bombbounds.top && shipbounds.top <= bombbounds.top + bombbounds.height)      // If the two bounding boxes are intersecting, then the player's ship has been hit.
                        {    
                            // Print the player's remaining life count.
                            cout <<"Lives:"<< --(p->lifes) <<endl;
                            dietimer=0;
                            p->candie=0;

                            // Respawn the player's ship at the default location.
                            p->x = 340;
                            p->y = 675;
                            p->sprite.setPosition(p->x, p->y);
    
                        }
                    }
                }    
            }    
        }
    }

      
    // Destroy
    if (level==1)
    {
        bool destroyed=1;
        if (l1.check1==1)
        {
            for(int i=0; i<10; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>25)
                destroyed=1;
            if (destroyed)
            {
                l1.check1=2;
                score+=300;
                for (int i=0; i<10; i++)
                    delete attack[i].bomb;
                delete[] attack;
            
                bombtimer=0;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l1.check2==1)
        {
            for(int i=0; i<9; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>5)
                destroyed=1;
            if (destroyed)
            {
                l1.check2=2;
                score+=300;
                bombtimer=0;
                for (int i=0; i<9; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l1.check3==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>5)
                destroyed=1;
            if (destroyed)
            {
                l1.check3=2;
                score+=300;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l1.monbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l1.monbool=2;
                score+=500;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l1.dragbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>5)
                destroyed=1;
            if (destroyed)
            {
                l1.dragbool=2;
                score+=500;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }        
    }
    else if (level==2)
    {
        bool destroyed=1;
        if (l2.check1==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>5)
                destroyed=1;
            if (destroyed)
            {
                l2.check1=2;
                score+=500;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l2.check2==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l2.check2=2;
                score+=500;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l2.check3==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l2.check3=2;
                score+=500;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l2.monbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l2.monbool=2;
                score+=700;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l2.dragbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l2.dragbool=2;
                score+=700;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }        
    }
    else if (level==3)
    {
        bool destroyed=1;
        if (l3.check1==1)
        {
            for(int i=0; i<10; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.check1=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<10; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l3.check2==1)
        {
            for(int i=0; i<9; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>2)
                destroyed=1;
            if (destroyed)
            {
                l3.check2=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<9; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l3.check3==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.check3=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l3.check4==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.check4=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l3.check5==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.check5=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l3.check6==1)
        {
            for(int i=0; i<12; i++)
            {
                if (attack[i].present)
                    destroyed=0;
            }
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.check6=2;
                score+=700;
                bombtimer=0;
                for (int i=0; i<12; i++)
                    delete attack[i].bomb;
                delete[] attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }    
        else if (l3.monbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.monbool=2;
                score+=1000;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }
        else if (l3.dragbool==1)
        {
            if (attack->present)
                destroyed=0;
            if (enemytimer>12)
                destroyed=1;
            if (destroyed)
            {
                l3.dragbool=2;
                score+=1000;
                bombtimer=0;
                delete[] attack->bomb;
                delete attack;
                attack= nullptr;
                enemytimer=0;
            }    
        }        
    }
    
    // Add-ons
    if ( p-> adds == nullptr)
    {
        int x = rand()%5000;
        if ( x == 1)
        {
            p -> adds = new Danger( (rand()%560+80), (rand()%380+400) );
            addtimer=0;
            addnum=1;
        }
        else if ( x == 100)
        {
            p -> adds = new Life( (rand()%560+80), (rand()%380+400) );
            addtimer=0;
            addnum=2;
        }
        else if ( x == 200)
        {
            p -> adds = new Fire( (rand()%560+80), (rand()%380+400) );
            addtimer=0;
            addnum=3;
        }
        else if ( x == 400)
        {
            p -> adds = new Power_up( (rand()%560+80), (rand()%380+400) );
            addtimer=0;
            addnum=4;
        }

    }
    if ( p-> adds != nullptr )
    {
        if (addtimer>10)
        {
            delete p->adds;
            p->adds= nullptr;
            addnum=0;
        }
        else
        {
            FloatRect addbounds= p->adds->sprite.getGlobalBounds();
            FloatRect shipbounds= p->sprite.getGlobalBounds();
            if (shipbounds.left + shipbounds.width >= addbounds.left && shipbounds.left <= addbounds.left + addbounds.width &&  shipbounds.top + shipbounds.height >= addbounds.top && shipbounds.top <= addbounds.top + addbounds.height)
            {
                
                if (addnum==1)
                {
                    // Print the player's remaining life count.
                    cout <<"Lives:"<< --(p->lifes) <<endl;

                    // Respawn the player's ship at the default location.
                    p->x = 340;
                    p->y = 675;
                    p->sprite.setPosition(p->x, p->y);
                    if (p->power!=0)
                    {
                        p->candie=1;
                        p->power=0;
                    }
                }
                else if (addnum==2)
                {
                    // Print the player's remaining life count.
                    cout <<"Lives:"<< ++(p->lifes) <<endl;
                    if (p->power!=0)
                    {
                        p->candie=1;
                        p->power=0;
                    }      
                }
                else if (addnum==3)
                {
                    p-> power=1;                    
                }                 
                else if (addnum==4)
                {
                    p-> power=2;
                    p->candie=0;
                    cout<<"Can't die\n";
                }
                addtimer=0;
                powertimer=0;
                if ( p->adds!= nullptr)
                {
                    delete p->adds;
                    p->adds= nullptr;
                }
                addnum=0;
            }
        }    
    }    
    if ( p->power!=0 && powertimer>10)
    {
        p->candie=1;
        p->power=0;
    }

    //////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	for (int i=0; i<p->numbul; i++)
        if (p->b[i].active)
            window.draw(p->b[i].bulsprite);   // Drawing Bullets

    // Drawing enemies
    if (level==1)
    {
        if (attack!=nullptr)
        {
            if (l1.check1==1)
            {
                for (int i=0; i<10; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l1.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l1.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l1.monbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<3; i++) 
                    window.draw(attack->bomb[i].sprite);  
            }
            else if ( l1.dragbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<7; i++) 
                    window.draw(attack->bomb[i].sprite);    
            }
        }
    }
    else if (level==2)
    {
        if (attack!=nullptr)
        {
            if (l2.check1==1 || l2.check2==1 || l2.check3==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l2.monbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<3; i++) 
                    window.draw(attack->bomb[i].sprite);  
            }
            else if ( l2.dragbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<7; i++) 
                    window.draw(attack->bomb[i].sprite);    
            }
        
        }
    }
    else if (level==3)
    {
        if (attack!=nullptr)
        {
            if (l3.check1==1)
            {
                for (int i=0; i<10; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l3.check2==1)
            {
                for (int i=0; i<9; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l3.check3==1 || l3.check4==1 || l3.check5==1 || l3.check6==1)
            {
                for (int i=0; i<12; i++)
                {
                    if (attack[i].present)
                    {
                        window.draw(attack[i].ensprite);
                        window.draw(attack[i].bomb->sprite);
                    }
                }
            }
            else if (l3.monbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<3; i++) 
                    window.draw(attack->bomb[i].sprite);  
            }
            else if ( l3.dragbool==1)
            {
                window.draw(attack->ensprite);
                for (int i=0; i<7; i++) 
                    window.draw(attack->bomb[i].sprite);    
            }
        
        }
    }      
    
    // Drawing addon
    if ( p-> adds != nullptr )
        window.draw ( p->adds->sprite);
    for (int i=0; i< p->lifes; i++)
    {
        p-> lifesprite.setPosition( i*20 , 750 );
        window.draw( p-> lifesprite);
    }
    text2.setPosition(200,750);
    text2.setString ("Level: " + to_string(level));
    window.draw(text2);
    text2.setPosition(400,750);
    text2.setString ("Bullet: " + to_string(p->numbul));
    window.draw(text2);
    text2.setPosition(600,750);
    text2.setString("Score: "+ to_string(score));
    window.draw(text2);
    
    window.display();  //Displying0 all the sprites
    }


}

};