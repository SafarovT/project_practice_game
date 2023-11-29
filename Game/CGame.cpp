#include "CGame.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

void CGame::Start()
{
    sf::ContextSettings m_settings;
    m_settings.antialiasingLevel = 8;
    sf::RenderWindow m_window = sf::RenderWindow
    (
        sf::VideoMode(1024, 780),
        "Pointer follows mouse",
        sf::Style::Default,// sf::Style::Fullscreen,
        m_settings
    );

    while (m_window.isOpen())
    {
        m_window.clear();
        m_elements.UpdateAndDraw(m_window);
        m_window.display();
    }
}
