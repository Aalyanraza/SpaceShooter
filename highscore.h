#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

class Highscore
{
public:
    sf::Sprite sprite;
    sf::Texture tex;
    sf::Text text;
    sf::Font font;

    Highscore()
    {
        tex.loadFromFile("img/highscore.jpg");
        sprite.setTexture(tex);
        sprite.setScale(2, 1.25);
        font.loadFromFile("img/arial.ttf");

        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
    }

    void display(sf::RenderWindow& window)
    {
        int score1[100];

        std::ifstream infile("file.txt"); // Input
        int index = 0;
        while (infile >> score1[index])
        {
            index++;
        }
        infile.close();

        for (int i = 0; i < index; i++) // Descending order
        {
            for (int j = i + 1; j < index; j++)
            {
                int temp = 0;
                if (score1[i] < score1[j])
                {
                    temp = score1[i];
                    score1[i] = score1[j];
                    score1[j] = temp;
                }
            }
        }

        while (window.isOpen()) // Keep the window open until the user closes it
        {
            sf::Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) // If B is pressed
                return;

            window.clear(sf::Color::Black);
            window.draw(sprite);

            for (int i = 0; i < index && i < 10; i++)
            {
                text.setPosition(120, 210 + i * 40);
                text.setString(to_string(i + 1) + ". " + to_string(score1[i]));
                window.draw(text);
            }

            window.display();
        }
    }
};

#endif // HIGHSCORE_H
