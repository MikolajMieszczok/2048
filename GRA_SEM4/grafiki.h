#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class grafiki
{
public:
	std::vector<sf::Texture>obrazy;
	sf::Texture texture;
	void zaladuj_grafiki()
	{
		texture.loadFromFile("3.png");
		obrazy.push_back(texture);
		texture.loadFromFile("6.png");
		obrazy.push_back(texture);
		texture.loadFromFile("12.png");
		obrazy.push_back(texture);
		texture.loadFromFile("24.png");
		obrazy.push_back(texture);
		texture.loadFromFile("48.png");
		obrazy.push_back(texture);
		texture.loadFromFile("96.png");
		obrazy.push_back(texture);
		texture.loadFromFile("192.png");
		obrazy.push_back(texture);
		texture.loadFromFile("384.png");
		obrazy.push_back(texture);
		texture.loadFromFile("768.png");
		obrazy.push_back(texture);
		texture.loadFromFile("1536.png");
		obrazy.push_back(texture);
		texture.loadFromFile("3072.png");
		obrazy.push_back(texture);
	}
};