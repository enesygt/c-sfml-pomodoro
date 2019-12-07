#include "kronometre.h"


kronometre::kronometre()
{
    kron_minute = 0;
    kron_second = 59;
    this->init();
    time_finish_flag = false;
}

kronometre::~kronometre()
{ }

void kronometre::clock_work()
{
    /** Take elapsed time */
    this->time = this->clock.getElapsedTime() + time_2;

    /** Convert time to second.*/
    this->second = this->time.asSeconds();

    kron_second = 59 - second;


    if (this->kron_second == -1) {
        if (kron_minute == 0) {
            clock_work_flag  = false;
            time_finish_flag = true;
        } else {
            this->kron_minute--;
        }

        this->clock.restart();
        this->time_2 = time_2.Zero;

        /*if(this->minute>minute_limit)
         *      this->minute=0;*/
        /*
         *              this->clock.restart();
         *              this->second = 0;*/
    } else {
        /* If minute is smaller than 10, add 0 side ofminute digit  */
        if (this->kron_minute < 10)
            this->minutes = "0" + std::to_string(kron_minute);
        else
            this->minutes = std::to_string(kron_minute);

        if (kron_second < 10)
            this->seconds = "0" + std::to_string(kron_second);
        else
            this->seconds = std::to_string(kron_second);
    }
    this->t_kronometre.setString(minutes + ":" + seconds);
}// kronometre::clock_work

void kronometre::init()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Kronometre");
    this->font.loadFromFile("Unicorn Pop.ttf");
    if (!font.loadFromFile("Unicorn Pop.ttf")) {
        // error...
        std::cout << "Error loading font!";
    }
    this->t_kronometre.setCharacterSize(50);
    this->t_kronometre.setFillColor(sf::Color::Green);
    this->t_kronometre.setFont(font);
    this->t_kronometre.setPosition(50.0f, 50.0f);

    this->tex.loadFromFile("but1.png", sf::IntRect(0, 0, 300, 300));

    this->tex_2.loadFromFile("but2.png", sf::IntRect(0, 0, 300, 300));
    spr.setTexture(tex);
    // spr.setTextureRect(sf::IntRect(0,0,250,250));
    spr.setPosition(300, 300);
}

void kronometre::update()
{
    if (this->window->isOpen()) {
        while (this->window->pollEvent(event)) {
            if (this->event.type == sf::Event::Closed) {
                this->window->close();
            } else if (this->event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i localPos = sf::Mouse::getPosition(*window);
                sf::Vector2f localPosF(static_cast<float>(localPos.x), static_cast<float>(localPos.y));
                auto translatedpos = this->window->mapPixelToCoords(localPos);
                if (!time_finish_flag) {
                    if (spr.getGlobalBounds().contains(translatedpos)) {
                        if (spr.getTexture() == &tex_2) {
                            spr.setTexture(tex);

                            clock_work_flag = true;
                            this->clock.restart();
                        } else {
                            if (clock_work_flag)
                                time_2 = this->clock.getElapsedTime() + time_2;

                            std::cout << static_cast<int>(time_2.asSeconds()) << std::endl;
                            spr.setTexture(tex_2);
                            clock_work_flag = false;
                        }
                    } else   { }
                }


                std::cout << "X::  " << localPos.x << " y: " << localPos.y << std::endl;
            }
        }
    }
}// kronometre::update

void kronometre::run()
{
    while (1) {
        if (this->clock_work_flag)
            this->clock_work();
        this->update();
        this->display();
    }
}

void kronometre::display()
{
    this->window->clear(sf::Color::White);
    this->window->draw(t_kronometre);
    this->window->draw(spr);

    this->window->display();
}
