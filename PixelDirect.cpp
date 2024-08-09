#include <sfml/Window.hpp>
#include <sfml/Graphics.hpp>
#include <iostream>

int main() {
    // create window
    //sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1280, 720), "Pixel Direct");

    sf::Window window = sf::Window(sf::VideoMode(1280, 720), "Pixel Direct");
    window.display();

    while (window.isOpen()) {

    }

    long cycles = 0;
    long millions = 0;
    while (millions < 2000) {
        cycles++;
        if (cycles == 1000000) {
            cycles = 0;
            millions++;
        }
    }

    std::cout << "Stopping after " << millions << " million cycles." << std::endl;

    return 0;
}