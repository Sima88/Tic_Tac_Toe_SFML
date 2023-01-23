#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include "Header.h"


int main() {
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(683, 677), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    sf::Texture board_texture;
    board_texture.loadFromFile("C:/mislav/polje.png");
    sf::Texture mark_x_texture;
    mark_x_texture.loadFromFile("C:/mislav/krizic.png");
    sf::Texture mark_o_texture;
    mark_o_texture.loadFromFile("C:/mislav/kruzic.png");
    sf::Texture win_texture;
    win_texture.loadFromFile("C:/mislav/win.png");
    sf::Texture play_again_texture;
    play_again_texture.loadFromFile("C:/mislav/playagain.png");
    sf::Texture draw_texture;
    draw_texture.loadFromFile("C:/mislav/draw.png");

    sf::Sprite board_sprite;
    board_sprite.setTexture(board_texture);
    board_sprite.setPosition(0.1, 0.1);
    sf::Sprite mark_x_sprite;
    mark_x_sprite.setTexture(mark_x_texture);
    mark_x_sprite.setScale(0.4, 0.4);
    sf::Sprite mark_o_sprite;
    mark_o_sprite.setTexture(mark_o_texture);
    mark_o_sprite.setScale(0.4, 0.4);
    sf::Sprite win_sprite;
    win_sprite.setTexture(win_texture);
    win_sprite.setScale(0.6, 0.6);
    win_sprite.setPosition(50, 100);
    sf::Sprite play_again_sprite;
    play_again_sprite.setTexture(play_again_texture);
    play_again_sprite.setScale(0.2, 0.2);
    play_again_sprite.setPosition(290, 440);
    sf::Sprite draw_sprite;
    draw_sprite.setTexture(draw_texture);
    draw_sprite.setPosition(180, 260);

    // Open a sound file
   // Declare a new sound buffer
    sf::SoundBuffer buffer;
    // Load it from a file
    if (!buffer.loadFromFile("C:/mislav/winsound.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    // Create a sound source and bind it to the buffer
    sf::Sound sound1;
    sound1.setBuffer(buffer);
    // Play the sound
    
   
    struct coordinate {
        int x;
        int y;
    };
    coordinate coordinate_model[9] = {
        {30, 40},{260, 40},{490, 40},
        {30, 260},{260, 260}, {490, 260},
        {30, 490},{260, 490}, {490, 490}

    };
    
    char current_mark = 'x';
    char board_model[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {

        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                    if (check_the_winner(board_model) || draw(board_model)) {
                        if ((event.mouseButton.x > 289 && event.mouseButton.x < 380) && (event.mouseButton.y > 441 && event.mouseButton.y < 532)) {
                           
                            board_model[0] = '1';
                            board_model[1] = '2';
                            board_model[2] = '3';
                            board_model[3] = '4';
                            board_model[4] = '5';
                            board_model[5] = '6';
                            board_model[6] = '7';
                            board_model[7] = '8';
                            board_model[8] = '9';
                       }
                    }
                    else {
                        int x_coordinate = event.mouseButton.x / 230;
                        int y_coordinate = event.mouseButton.y / 230;
                        int coordinates_on_the_board = y_coordinate * 3 + x_coordinate;

                         mouse_click(board_model, current_mark, coordinates_on_the_board);
                    }
                }
            }
           
        }
        // Activate the window for OpenGL rendering
        
        window.setActive();
        window.clear(sf::Color::White);
        
        window.draw(board_sprite);
       
        for (int i = 0; i < 9; i++) {

            auto current_coordinate = coordinate_model[i];
           
                switch (board_model[i])
                {
                case'x':
                    mark_x_sprite.setPosition(current_coordinate.x, current_coordinate.y);
                    window.draw(mark_x_sprite);
                    break;

                case'o':
                    mark_o_sprite.setPosition(current_coordinate.x, current_coordinate.y);
                    window.draw(mark_o_sprite);
                    break;
                default:
                    break;
                }
           
        }
        char again = 'a';
       
        if (check_the_winner(board_model)) {
            window.draw(win_sprite);
            window.draw(play_again_sprite);
        }
        if (draw(board_model)) {
            window.draw(draw_sprite);
            window.draw(play_again_sprite);
        }
     
        // OpenGL drawing commands go here...
        // End the current frame and display its contents on screen
        window.display();

    }
}

