#include <SFML/Graphics.hpp>
#include "Bat.cpp"
#include "Ball.cpp"
#include <sstream>

using namespace sf;

int main()
{
	VideoMode vm(960, 540);
	RenderWindow window(vm, "Pong Game");

	int score = 0;
	int lives = 3;
	bool gameOver = false;
	bool collision = false;
	Bat bat((960 / 2), 540 - 20);

	Ball ball((960 / 2), 20);
	ball.start();

	RectangleShape uiBar;
	uiBar.setSize(Vector2f(345, 55));
	uiBar.setFillColor(Color(10, 20, 40));
	uiBar.setPosition(0, 0);

	Text hub;
	Font font;
	font.loadFromFile("Fonts/KOMIKAP_.ttf");
	hub.setFont(font);
	hub.setCharacterSize(30);
	hub.setFillColor(Color::White);
	hub.setPosition(20, 20);

	Clock clock;

	while (window.isOpen())
	{
		Time dt = clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard ::isKeyPressed(Keyboard::Escape))
				window.close();
			if (gameOver && event.type == Event::KeyPressed && event.key.code == Keyboard::R)
			{
				score = 0;
				lives = 3;
				gameOver = false;
				ball.reset(960 / 2, 20);
			}
		}
		if (!gameOver)
		{
			// bat event
			if (Keyboard ::isKeyPressed(Keyboard::Left))
				bat.moveLeft();
			else
				bat.stopLeft();

			if (Keyboard ::isKeyPressed(Keyboard::Right))
				bat.moveRight();
			else
				bat.stopRight();

			bat.update(dt);
			ball.update(dt);

			// ball event
			if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
			{
				ball.reboundSides();
			}
			if (ball.getPosition().top < 0)
			{
				ball.reboundBatOrTop();
			}
			if (ball.getPosition().top > window.getSize().y)
			{
				lives--;
				if (lives < 1)
				{
					gameOver = true;
					ball.stop();
				}
				else
				{
					ball.reset((960 / 2), 20);
				}
			}

			if (ball.getPosition().intersects(bat.getPosition()) && !collision)
			{
				ball.reboundBatOrTop();
				ball.setPosition(
					ball.getPosition().left, 
					bat.getPosition().top - ball.getPosition().height
				);
				score++;
				collision = true;
			}
			if (ball.getPosition().top + ball.getPosition().height < bat.getPosition().top)
			{
				collision = false;
			}
		}
		std::stringstream ss;
		if (gameOver)
			ss << "Game Over! Final Score: " << score << "  Press R to restart!!";
		else
			ss << "Score: " << score << "    Lives: " << lives;
		hub.setString(ss.str());

		window.clear(Color(10, 20, 40));

		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(uiBar);
		window.draw(hub);
		window.display();
	}
	return 0;
}