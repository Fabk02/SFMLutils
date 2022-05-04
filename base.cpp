#include <SFML/Graphics.hpp>

void resize(sf::RenderWindow& window, sf::View& view, float height){
    float ratio{static_cast<float>(window.getSize().x)/static_cast<float>(window.getSize().y)};
    view.setSize(height*ratio,height);
    return;
}

int main(){
    unsigned int const w_width{640};
    unsigned int const w_height{360};

    sf::RenderWindow window(sf::VideoMode(w_width,w_height),"Title");
    sf::View view{window.getDefaultView()};

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

    while (window.isOpen())
    {
        pixelPos = sf::Mouse::getPosition(window);
        worldPos = window.mapPixelToCoords(pixelPos);
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::Resized:
                resize(window,view,w_height);
                break;

            default:
                break;
            }
        }

        window.clear();
        window.display();
        
    }
    
}