

class Instructions
{
public:
    Sprite backgroundin; //Game background sprite
    Texture in_texture;
    

    Instructions()
    {
        in_texture.loadFromFile("img/instructions.jpg");
        backgroundin.setTexture(in_texture);
        backgroundin.setScale(1.2, 1.05);
    }

    void display( RenderWindow& window2)
    {
        while (window2.isOpen()) // Keep the window open until the user closes it
        {
            Event e;
            while (window2.pollEvent(e))
            {
                if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                    window2.close();   
            }
            if (Keyboard::isKeyPressed(Keyboard:: B)) // If I is pressed
                return;  

            window2.clear(Color::Black);
            window2.draw(backgroundin);
            window2.display();
        }
    }
};
