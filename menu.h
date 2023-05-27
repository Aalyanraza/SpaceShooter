
#include <fstream>
#include "game.h"
#include "instructions.h"
#include "highscore.h"
using namespace std;

class Menu
{
public:
    Sprite background;  //Menu background sprite
    Texture btexture;
    Sprite* botton;
    Texture bottontexture;
    Text text[5];
    Font font;
//add menu attributes here
Menu()
{
    btexture.loadFromFile("img/background_1.png");
    background.setTexture(btexture);
    background.setScale(2, 1.5);
    font.loadFromFile("img/arial.ttf");
    botton= new Sprite [5];    
    bottontexture.loadFromFile("img/PNG/UI/buttonBlue.png");
    for (int i=0; i<5; i++)
        botton[i].setTexture(bottontexture);
    
    botton[0].setPosition(180,20); 
    botton[0].setScale(2,2.5); 
    text[0].setFont(font);  
    text[0].setString("To Resume, Press \"R\" ");  
    text[0].setCharacterSize(24);
    text[0].setFillColor( Color:: Black);
    text[0].setPosition(220,50); 
    
    botton[1].setPosition(180,170);
    botton[1].setScale(2,2.5);
    text[1].setFont(font);  
    text[1].setString("To Start, Press \"S\" ");  
    text[1].setCharacterSize(24);
    text[1].setFillColor( Color::Black);
    text[1].setPosition(220,200) ; 
    
    botton[2].setPosition(180,320);    
    botton[2].setScale(2,2.5);
    text[2].setFont(font);  
    text[2].setString("For HighScore, Press \"H\" ");  
    text[2].setCharacterSize(24);
    text[2].setFillColor( Color::Black);
    text[2].setPosition(220,350) ; 

    botton[3].setPosition(180,470);    
    botton[3].setScale(2,2.5);
    text[3].setFont(font);  
    text[3].setString("For Instructions, Press \"I\" ");  
    text[3].setCharacterSize(24);
    text[3].setFillColor( Color::Black);
    text[3].setPosition(220,500) ; 

    botton[4].setPosition(180,620);    
    botton[4].setScale(2,2.5);
    text[4].setFont(font);  
    text[4].setString("To Exit, Press \"E\" ");  
    text[4].setCharacterSize(24);
    text[4].setFillColor( Color::Black);
    text[4].setPosition(220,650) ; 
    
}

void display_menu()
{
    RenderWindow window1(VideoMode(780, 780), title);
    while (window1.isOpen())
    {
        Event e;
        char option;
        while (window1.pollEvent(e))
        {  
            if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard:: E)) // If cross/close is clicked/pressed
                window1.close(); //close the game                        	    
        }
          
        if (Keyboard::isKeyPressed(Keyboard:: R)) //If R is pressed
            option= 'r';    
        if (Keyboard::isKeyPressed(Keyboard:: S)) // If S is pressed
            option= 's';  
        if (Keyboard::isKeyPressed(Keyboard:: H)) //If H is pressed
            option= 'h';    
        if (Keyboard::isKeyPressed(Keyboard:: I)) // If I is pressed
            option= 'i';  

//display menu screen here
    window1.clear(Color::Black); //clears the screen
    window1.draw(background);  // setting background
    for (int i=0; i<5; i++)
        window1.draw(botton[i]);
    for (int i=0; i<5; i++)
        window1.draw(text[i]);       
    
    window1.display();  //Displying all the sprites

// add functionality of all the menu options here

//if Start game option is chosen 
    
    if ( option == 's' || option == 'r')
    {
        Game g;
        g.start_game( window1 );
        option=' ';
    }

    else if ( option == 'i')
    {
        Instructions i;
        i.display( window1 );
        option=' ';
        
    }
    else if (option == 'h')
    {
        Highscore h;
        h.display( window1 );
    }

    }
}
};
