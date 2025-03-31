#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
	window.setFramerateLimit(144);

	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			// left key is pressed: move our character
			circle.move({-1.f, 0.f});
		}

		window.clear();
		window.draw(circle);
		window.display();
	}
}
