#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "Platform.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"
#include <iostream>
// Load the music (we have used Celeste game music)
sf::Music music;
bool musicPlayPause() {
    if (!music.openFromFile("resources/CelesteSoundTrack.ogg")) {
        return false;
    }
    music.setLoop(true);
    music.play();
    return true;
}

//main function starting from here
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D-PLATFORMER");

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        return -1;
    }
    // Load the music
    if (!musicPlayPause()) {
        return -1;
    }


    // Create buttons
    Button playButton({ 200, 50 }, { 300, 250 }, "Play", font);
    Button exitButton({ 200, 50 }, { 300, 350 }, "Exit", font);
    Button resumeButton({ 200, 50 }, { 300, 250 }, "Resume", font);
    Button restartButton({ 200, 50 }, { 300, 350 }, "Restart", font);
    Button playagainButton({ 200, 50 }, { 300, 350 }, "Play Again", font);
    Button exitEndButton({ 200, 50 }, { 300, 440 }, "Exit", font);

    //LEVEL 1
    // Create platforms 
    std::vector<Platform> L1platforms;
    L1platforms.push_back(Platform(200.f, 20.f, 0.f, 480.f));
    L1platforms.push_back(Platform(200.f, 20.f, 300.f, 390.f));
    L1platforms.push_back(Platform(200.f, 20.f, 600.f, 290.f));
    L1platforms.push_back(Platform(820.f, 20.f, -10.f, 580.f));//Ground
    // Create a door
    sf::RectangleShape Door1(sf::Vector2f(70.f, 100.f));
    Door1.setPosition(700, 190.f);
    // Create player and enemies 
    Player player1(230.f, 200.f);
    Enemy L1enemy1(420.f, 370.f, 50.f, 20.f); // Positioned on the second platform
    Enemy L1enemy2(50.f, 460.f, 50.f, 20.f); // Positioned on the first platform 
    Enemy L1enemy3(500.f, 560.f, 50.f, 20.f);// on Ground


    //LEVEL 2
    // Create platforms 
    std::vector<Platform> L2platforms;
    L2platforms.push_back(Platform(200.f, 20.f, 0.f, 150.f));
    L2platforms.push_back(Platform(200.f, 20.f, 300.f, 200.f));
    L2platforms.push_back(Platform(200.f, 20.f, 600.f, 300.f));
    L2platforms.push_back(Platform(200.f, 20.f, 300.f, 400.f));
    L2platforms.push_back(Platform(200.f, 20.f, 0.f, 490.f));
    L2platforms.push_back(Platform(820.f, 20.f, -10.f, 580.f));//Ground
    // Create a door
    sf::RectangleShape Door2(sf::Vector2f(70.f, 100.f));
    Door2.setPosition(10.f, 50.f);
    // Create player and enemies 
    Player player2(30.f, 538.f);
    Enemy L2enemy1(420.f, 380.f, 50.f, 20.f); // Positioned on the right platform
    Enemy L2enemy2(700.f, 280.f, 50.f, 20.f); // Positioned on the right platform 
    Enemy L2enemy3(500.f, 560.f, 50.f, 20.f);// on Ground
    Enemy L2enemy4(350.f, 180.f, 50.f, 20.f); // top most center platform
    Enemy L2enemy5(30.f, 470.f, 50.f, 20.f);

    //LEVEL 3
    //Create platforms
    std::vector<Platform> L3platforms;
    L3platforms.push_back(Platform(600.f, 20.f, 0.f, 170.f));
    L3platforms.push_back(Platform(600.f, 20.f, 200.f, 300.f));
    L3platforms.push_back(Platform(600.f, 20.f, 0.f, 430.f));
    L3platforms.push_back(Platform(820.f, 20.f, -10.f, 560.f));//Ground
    // Create a door
    sf::RectangleShape Door3(sf::Vector2f(70.f, 100.f));
    Door3.setPosition(20.f, 70.f);
    // Create player and enemies 
    Player player3(200.f, 460.f);
    Enemy L3enemy1(420.f, 150.f, 50.f, 20.f); // Positioned on the second platform
    Enemy L3enemy2(350.f, 280.f, 50.f, 20.f); // Positioned on the first platform 
    Enemy L3enemy3(300.f, 410.f, 50.f, 20.f);// on Ground
    Enemy L3enemy4(200.f, 540.f, 50.f, 20.f);

    //LEVEL 4
    //Create platforms
    std::vector<Platform> L4platforms;
    L4platforms.push_back(Platform(150.f, 20.f, 0.f, 580.f));//Ground
    L4platforms.push_back(Platform(100.f, 20.f, 250.f, 310.f, true, 0.f, 75.0f, 0.0f, 200.0f));
    L4platforms.push_back(Platform(100.f, 20.f, 450.f, 100.f, true, 0.f, 150.0f, 0.0f, 190.0f));
    L4platforms.push_back(Platform(150.f, 20.f, 650.f, 120.f));
    //L4platforms.push_back(Platform(820.f, 20.f, -10.f, 580.f));//Ground
    // Create a door
    sf::RectangleShape Door4(sf::Vector2f(70.f, 100.f));
    Door4.setPosition(700.f, 20.f);
    //// Create player and enemies 
    Player player4(20.f, 540.f);

    //LEVEL 5
    //Create platforms
    std::vector<Platform> L5platforms;
    L5platforms.push_back(Platform(150.f, 20.f, 0.f, 580.f));//Ground
    L5platforms.push_back(Platform(100.f, 20.f, 250.f, 250.f, true, 100.f, 0.f, 200.0f, 0.f));
    L5platforms.push_back(Platform(100.f, 20.f, 250.f, 450.f, true, 100.f, 0.f, 200.0f, 0.f));
    L5platforms.push_back(Platform(100.f, 20.f, 650.f, 270.f, true, 0.f, 100.f, 0.f, 160.f));
    L5platforms.push_back(Platform(150.f, 20.f, 0.f, 140.f));
    //L5platforms.push_back(Platform(820.f, 20.f, -10.f, 580.f));//Ground
    // Create a door
    sf::RectangleShape Door5(sf::Vector2f(70.f, 100.f));
    Door5.setPosition(30.f, 40.f);
    //// Create player and enemies 
    Player player5(20.f, 540.f);



    // Define game states
    enum class GameState {
        MainMenu,
        Level1,
        Level2,
        Level3,
        Level4,
        Level5,
        Paused,
        GameOver,
        GameCompleted
    };
    GameState currentState = GameState::MainMenu;
    int currentLevel;

    // Load textures
    sf::Texture playerTexture, enemyTexture, platformTexture, doorTexture;
    if (!playerTexture.loadFromFile("resources/assets/player.jpg") ||
        !enemyTexture.loadFromFile("resources/assets/enemy.jpg") ||
        !platformTexture.loadFromFile("resources/assets/platform.jpg") ||
        !doorTexture.loadFromFile("resources/assets/Gamedoor.jpg"))

    {
        return -1; // Exit if textures cannot be loaded
    }

    // Apply textures for levels.
    player1.setTexture(playerTexture);
    L1enemy1.setTexture(enemyTexture);
    L1enemy2.setTexture(enemyTexture);
    L1enemy3.setTexture(enemyTexture);
    for (auto& platform : L1platforms) {
        platform.setTexture(platformTexture);
    }
    player2.setTexture(playerTexture);
    L2enemy1.setTexture(enemyTexture);
    L2enemy2.setTexture(enemyTexture);
    L2enemy3.setTexture(enemyTexture);
    L2enemy4.setTexture(enemyTexture);
    L2enemy5.setTexture(enemyTexture);
    for (auto& platform : L2platforms) {
        platform.setTexture(platformTexture);
    }
    player3.setTexture(playerTexture);
    L3enemy1.setTexture(enemyTexture);
    L3enemy2.setTexture(enemyTexture);
    L3enemy3.setTexture(enemyTexture);
    L3enemy4.setTexture(enemyTexture);
    for (auto& platform : L3platforms) {
        platform.setTexture(platformTexture);
    }
    player4.setTexture(playerTexture);
    for (auto& platform : L4platforms) {
        platform.setTexture(platformTexture);
    }
    player5.setTexture(playerTexture);
    for (auto& platform : L5platforms) {
        platform.setTexture(platformTexture);
    }


    // Clock for delta time
    sf::Clock deltaClock;

    // MAIN GAME LOOP
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (currentState == GameState::MainMenu) {
                    if (playButton.isClicked(sf::Mouse::getPosition(window))) {
                        currentState = GameState::Level1;
                        Door1.setTexture(&doorTexture);
                        music.play();
                    }
                    if (exitButton.isClicked(sf::Mouse::getPosition(window))) {
                        window.close();
                    }
                }
                if (currentState == GameState::Paused) {
                    if (resumeButton.isClicked(sf::Mouse::getPosition(window))) {
                        /*currentState = GameState::Level1;
                        Door1.setTexture(&doorTexture);*/

                        // Resume the game to the correct level based on currentLevel
                        if (currentLevel == 1) {
                            currentState = GameState::Level1;
                            Door1.setTexture(&doorTexture);
                        }
                        else if (currentLevel == 2) {
                            currentState = GameState::Level2;
                            Door2.setTexture(&doorTexture);
                        }
                        else if (currentLevel == 3) {
                            currentState = GameState::Level3;
                            Door3.setTexture(&doorTexture);
                        }
                        else if (currentLevel == 4) {
                            currentState = GameState::Level4;
                            Door4.setTexture(&doorTexture);
                        }
                        else if (currentLevel == 5) {
                            currentState = GameState::Level5;
                            Door5.setTexture(&doorTexture);
                        }
                        music.play();
                    }
                }
            }
        }

        // Check for pause key press during Level1
        if (currentState == GameState::Level1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentState = GameState::Paused;
            music.pause();
        }
        // Check for pause key press during Level2
        if (currentState == GameState::Level2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentState = GameState::Paused;
            music.pause();
        }
        // Check for pause key press during Level3
        if (currentState == GameState::Level3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentState = GameState::Paused;
            music.pause();
        }
        if (currentState == GameState::Level4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentState = GameState::Paused;
            music.pause();
        }
        if (currentState == GameState::Level5 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentState = GameState::Paused;
            music.pause();
        }

        // Get delta time
        sf::Time deltaTime = deltaClock.restart(); // Restarts the clock and gets the elapsed time

        // Clear the window
        window.clear();

        // Render based on the current game state
        if (currentState == GameState::MainMenu) {
            sf::Text MainMenuText;
            MainMenuText.setFont(font);
            MainMenuText.setString("\t\t\t\tMain Menu\n");
            MainMenuText.setCharacterSize(30);
            MainMenuText.setFillColor(sf::Color::White);
            MainMenuText.setPosition(200, 150);
            window.draw(MainMenuText);
            playButton.draw(window);
            exitButton.draw(window);
            music.pause();
        }
        else if (currentState == GameState::Level1) {
            currentLevel = 1;
            window.clear(sf::Color::Black);
            window.draw(Door1);
            // Draw platforms
            for (auto& platform : L1platforms) {
                platform.draw(window);
            }

            // Update and draw the player
            player1.update(deltaTime, L1platforms); // Pass platforms to detect collisions
            player1.draw(window);

            // Update and draw enemies
            L1enemy1.update(deltaTime, 302.f, 498.f);
            L1enemy1.draw(window);

            L1enemy2.update(deltaTime, 02.f, 198.f);
            L1enemy2.draw(window);

            L1enemy3.update(deltaTime, 02.f, 798.f);
            L1enemy3.draw(window);

            // Check for collision between player and enemy
            if (player1.getBounds().intersects(L1enemy1.getBounds()) || player1.getBounds().intersects(L1enemy2.getBounds()) || player1.getBounds().intersects(L1enemy3.getBounds())) {
                currentState = GameState::GameOver; // Switch to Game Over state
                music.pause();
            }
            if (player1.getBounds().intersects(Door1.getGlobalBounds())) {
                currentLevel = 2;
                currentState = GameState::Level2;

                // Reset Level 2 state
                Door2.setTexture(&doorTexture); // Assign door texture


                // Initialize Level 2 enemies, platforms, and player
                L2enemy1 = Enemy(420.f, 380.f, 50.f, 20.f);
                L2enemy2 = Enemy(700.f, 280.f, 50.f, 20.f);
                L2enemy3 = Enemy(500.f, 560.f, 50.f, 20.f);
                L2enemy4 = Enemy(350.f, 180.f, 50.f, 20.f);
                L2enemy5 = Enemy(30.f, 470.f, 50.f, 20.f);
                player2 = Player(30.f, 538.f);


                // Apply textures
                player2.setTexture(playerTexture);
                L2enemy1.setTexture(enemyTexture);
                L2enemy2.setTexture(enemyTexture);
                L2enemy3.setTexture(enemyTexture);
                L2enemy4.setTexture(enemyTexture);
                L2enemy5.setTexture(enemyTexture);
                for (auto& platform : L2platforms) {
                    platform.setTexture(platformTexture);
                }
            }

        }
        else if (currentState == GameState::Level2) {
            window.clear(sf::Color::Black);
            window.draw(Door2);
            Door2.setTexture(&doorTexture);
            // Draw platforms
            for (auto& platform : L2platforms) {
                platform.draw(window);
            }


            // Update and draw the player
            player2.update(deltaTime, L2platforms); // Pass platforms to detect collisions
            player2.draw(window);

            // Update and draw enemies
            L2enemy1.update(deltaTime, 302.f, 498.f);
            L2enemy1.draw(window);

            L2enemy2.update(deltaTime, 602.f, 798.f);
            L2enemy2.draw(window);

            L2enemy3.update(deltaTime, 2.f, 802.f);
            L2enemy3.draw(window);

            L2enemy4.update(deltaTime, 302.f, 498.f);
            L2enemy4.draw(window);

            L2enemy5.update(deltaTime, 2.f, 198.f);
            L2enemy5.draw(window);

            // Check for collision between player and enemy
            if (player2.getBounds().intersects(L2enemy1.getBounds()) || player2.getBounds().intersects(L2enemy2.getBounds()) || player2.getBounds().intersects(L2enemy3.getBounds()) || player2.getBounds().intersects(L2enemy4.getBounds()) || player2.getBounds().intersects(L2enemy5.getBounds())) {
                currentState = GameState::GameOver; // Switch to Game Over state
                music.pause();
            }
            if (player2.getBounds().intersects(Door2.getGlobalBounds())) {
                currentLevel = 3;
                currentState = GameState::Level3;
                // Reset Level 3 state
                Door3.setTexture(&doorTexture); // Assign door texture


                // Initialize Level 3 enemies, platforms, and player
                L3enemy1 = Enemy(420.f, 150.f, 50.f, 20.f);
                L3enemy2 = Enemy(350.f, 280.f, 50.f, 20.f);
                L3enemy3 = Enemy(300.f, 410.f, 50.f, 20.f);
                L3enemy4 = Enemy(200.f, 540.f, 50.f, 20.f);
                player3 = Player(200.f, 460.f);

                // Apply textures
                player3.setTexture(playerTexture);
                L3enemy1.setTexture(enemyTexture);
                L3enemy2.setTexture(enemyTexture);
                L3enemy3.setTexture(enemyTexture);
                L3enemy4.setTexture(enemyTexture);
                for (auto& platform : L3platforms) {
                    platform.setTexture(platformTexture);
                }
            }
        }
        else if (currentState == GameState::Level3) {
            window.clear(sf::Color::Black);
            Door3.setTexture(&doorTexture);
            window.draw(Door3);
            // Draw platforms
            for (auto& platform : L3platforms) {
                platform.draw(window);
            }
            // Update and draw the player
            player3.update(deltaTime, L3platforms); // Pass platforms to detect collisions
            player3.draw(window);

            // Update and draw enemies
            L3enemy1.update(deltaTime, 2.f, 598.f);
            L3enemy1.draw(window);

            L3enemy2.update(deltaTime, 202.f, 798.f);
            L3enemy2.draw(window);

            L3enemy3.update(deltaTime, 2.f, 598.f);
            L3enemy3.draw(window);

            L3enemy4.update(deltaTime, 02.f, 802.f);
            L3enemy4.draw(window);


            // Check for collision between player and enemy
            if (player3.getBounds().intersects(L3enemy1.getBounds()) || player3.getBounds().intersects(L3enemy2.getBounds()) || player3.getBounds().intersects(L3enemy3.getBounds()) || player3.getBounds().intersects(L3enemy4.getBounds())) {
                currentState = GameState::GameOver; // Switch to Game Over state
                music.pause();
            }
            if (player3.getBounds().intersects(Door3.getGlobalBounds())) {

                currentLevel = 4;
                currentState = GameState::Level4;
                // Reset Level 3 state
                Door4.setTexture(&doorTexture); // Assign door texture           
                player4 = Player(20.f, 540.f);

                // Apply textures
                player4.setTexture(playerTexture);
                for (auto& platform : L4platforms) {
                    platform.setTexture(platformTexture);
                }
            }
        }
        else if (currentState == GameState::Level4) {
            window.clear(sf::Color::Black);
            Door4.setTexture(&doorTexture);
            window.draw(Door4);
            // Draw platforms
            for (auto& platform : L4platforms) {
                platform.update(deltaTime.asSeconds());
                platform.draw(window);
            }
            // Update and draw the player
            player4.update(deltaTime, L4platforms); // Pass platforms to detect collisions
            player4.draw(window);
            sf::Vector2f player4Pos = player4.getPosition();

            // Check if player fell off screen
            if (player4.isDead) {
                std::cout << "Player fell! Game Over triggered.\n";
                currentState = GameState::GameOver;
                music.pause();
            }

            if (player4.getBounds().intersects(Door4.getGlobalBounds())) {
                currentState = GameState::Level5;
                currentLevel = 5;
                Door5.setTexture(&doorTexture); // Assign door texture           
                player5 = Player(20.f, 540.f);

                // Apply textures
                player5.setTexture(playerTexture);
                for (auto& platform : L5platforms) {
                    platform.setTexture(platformTexture);
                }
            }
        }
        else if (currentState == GameState::Level5) {
            window.clear(sf::Color::Black);
            Door5.setTexture(&doorTexture);
            window.draw(Door5);
            // Draw platforms
            for (auto& platform : L5platforms) {
                platform.update(deltaTime.asSeconds());
                platform.draw(window);
            }
            // Update and draw the player
            player5.update(deltaTime, L5platforms); // Pass platforms to detect collisions
            player5.draw(window);
            sf::Vector2f player5Pos = player5.getPosition();
            // Check if player fell off screen
            if (player5.isDead) {
                std::cout << "Player fell! Game Over triggered.\n";
                currentState = GameState::GameOver;
                music.pause();
            }

            if (player5.getBounds().intersects(Door5.getGlobalBounds())) {
                currentState = GameState::GameCompleted;
                music.pause();
            }
        }
        else if (currentState == GameState::Paused) {
            sf::Text pauseText;
            pauseText.setFont(font);
            pauseText.setString("Game Paused");
            pauseText.setCharacterSize(40);
            pauseText.setFillColor(sf::Color::White);
            pauseText.setPosition(280, 150);

            window.draw(pauseText);
            resumeButton.draw(window);
        }
        else if (currentState == GameState::GameOver) {

            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("\t\t\tGame Over!\n");
            gameOverText.setCharacterSize(30);
            gameOverText.setFillColor(sf::Color::White);
            gameOverText.setPosition(200, 150);

            window.draw(gameOverText);
            restartButton.draw(window);

            // Check for restart button click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                restartButton.isClicked(sf::Mouse::getPosition(window))) {
                // Reset the game state
                currentState = GameState::Level1;
                music.play();

                // Reset player and enemy positions
                player1 = Player(230.f, 200.f);
                L1enemy1 = Enemy(420.f, 370.f, 50.f, 20.f);
                L1enemy2 = Enemy(50.f, 460.f, 50.f, 20.f);
                L1enemy3 = Enemy(500.f, 560.f, 50.f, 20.f);

                //Apply the textures
                player1.setTexture(playerTexture);
                L1enemy1.setTexture(enemyTexture);
                L1enemy2.setTexture(enemyTexture);
                L1enemy3.setTexture(enemyTexture);
                for (auto& platform : L1platforms) {
                    platform.setTexture(platformTexture);
                }
            }
        }
        else if (currentState == GameState::GameCompleted) {

            sf::Text completedText;
            completedText.setFont(font);
            completedText.setString("\t\t\t\t\tCongratulations!\n\n\t\t\t\t\tGame Completed");
            completedText.setCharacterSize(30);
            completedText.setFillColor(sf::Color::White);
            completedText.setPosition(150, 150);

            window.draw(completedText);


            //Check for exit key press
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            playagainButton.draw(window);
            exitEndButton.draw(window);

            // Check for restart button click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                playagainButton.isClicked(sf::Mouse::getPosition(window))) {
                // Reset the game state
                currentState = GameState::Level1;
                music.play();

                // Reset player and enemy positions
                player1 = Player(230.f, 200.f);
                L1enemy1 = Enemy(420.f, 370.f, 50.f, 20.f);
                L1enemy2 = Enemy(50.f, 460.f, 50.f, 20.f);
                L1enemy3 = Enemy(500.f, 560.f, 50.f, 20.f);
                //Apply the textures
                player1.setTexture(playerTexture);
                L1enemy1.setTexture(enemyTexture);
                L1enemy2.setTexture(enemyTexture);
                L1enemy3.setTexture(enemyTexture);
                for (auto& platform : L1platforms) {
                    platform.setTexture(platformTexture);
                }

            }
            // Check for exit button click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                exitEndButton.isClicked(sf::Mouse::getPosition(window))) {
                window.close();  // Close the game window
            }

        }
        // Display everything on the screen
        window.display();
    }
    return 0;
}
