#include "King.h"

// Create the ball
sf::CircleShape ball;
ball.setRadius(ballRadius - 3);
ball.setOutlineThickness(3);
ball.setOutlineColor(sf::Color::Black);
ball.setFillColor(sf::Color::White);
ball.setOrigin(ballRadius / 2, ballRadius / 2);

// Load the text font
sf::Font font;
if (!font.loadFromFile("resources/sansation.ttf"))
return EXIT_FAILURE;

// Initialize the pause message
sf::Text pauseMessage;
pauseMessage.setFont(font);
pauseMessage.setCharacterSize(40);
pauseMessage.setPosition(170.f, 150.f);
pauseMessage.setFillColor(sf::Color::White);
pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

// Define the paddles properties
sf::Clock AITimer;
const sf::Time AITime = sf::seconds(0.1f);
const float paddleSpeed = 400.f;
float rightPaddleSpeed = 0.f;
const float ballSpeed = 400.f;
float ballAngle = 0.f; // to be changed later


// Check the collisions between the ball and the paddles
            // Left Paddle
if (ball.getPosition().x - ballRadius < leftPaddle.getPosition().x + paddleSize.x / 2 &&
    ball.getPosition().x - ballRadius > leftPaddle.getPosition().x &&
    ball.getPosition().y + ballRadius >= leftPaddle.getPosition().y - paddleSize.y / 2 &&
    ball.getPosition().y - ballRadius <= leftPaddle.getPosition().y + paddleSize.y / 2)
{
    if (ball.getPosition().y > leftPaddle.getPosition().y)
        ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
    else
        ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;

    ballSound.play();
    ball.setPosition(leftPaddle.getPosition().x + ballRadius + paddleSize.x / 2 + 0.1f, ball.getPosition().y);
}

// Right Paddle
if (ball.getPosition().x + ballRadius > rightPaddle.getPosition().x - paddleSize.x / 2 &&
    ball.getPosition().x + ballRadius < rightPaddle.getPosition().x &&
    ball.getPosition().y + ballRadius >= rightPaddle.getPosition().y - paddleSize.y / 2 &&
    ball.getPosition().y - ballRadius <= rightPaddle.getPosition().y + paddleSize.y / 2)
{
    if (ball.getPosition().y > rightPaddle.getPosition().y)
        ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
    else
        ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;

    ballSound.play();
    ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);
}
        }