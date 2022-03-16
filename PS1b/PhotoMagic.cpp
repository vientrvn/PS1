// using SFML to load a file, manipulate its pixels, write it to disk

#include <iostream>
#include "FibLFSR.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void transform(sf::Image&, FibLFSR*);

int main(int argc, const char * argv[]) {
    sf::Image input_image, output_image;

	if (!input_image.loadFromFile(argv[1]))
		return -1;

    output_image = input_image;

    FibLFSR password(argv[3]);
    transform(output_image, &password);

	sf::Vector2u size = input_image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "McCabe Source File");
   	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Wicked Encrypted File"); 

	sf::Texture texture1, texture2;
	texture1.loadFromImage(input_image);
    texture2.loadFromImage(output_image);

	sf::Sprite sprite1, sprite2;
	sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);

	while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();

        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!output_image.saveToFile(argv[2]))
		return -1;

    return 0;
}

void transform(sf::Image& picture, FibLFSR* password){
    //p is a pixel_image.getPixel(x, y);
	sf::Color p;

	// create photographic negative image
	for (int x = 0; x < picture.getSize().x; x++) {
		for (int y = 0; y< picture.getSize().y; y++) {
			p = picture.getPixel(x, y);
			p.r ^= password->generate(8);
			p.g ^= password->generate(8);
			p.b ^= password->generate(8);
			picture.setPixel(x, y, p);
		}
	}
}