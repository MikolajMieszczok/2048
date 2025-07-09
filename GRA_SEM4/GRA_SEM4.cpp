#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <regex>
#include <filesystem>
#include <thread>
#include <iomanip>
#include <ranges>
#include "tablica.h"
#include "kwadraty.h"
#include "3072.h"
#include "grafiki.h"
#include "funkcje.h"
#include "Zegar.h"
#include "Logi.h"
#include "Nick.h"
#include "saves.h"  

using namespace std::chrono;
using namespace std::this_thread;

int main() {

    std::vector<int>indeksy_x;
    std::vector<int>indeksy_y;
    std::vector<int>kordynaty_x;
    std::vector<int>kordynaty_y;
    grafiki do_gry;
    Clock zegar;
    do_gry.zaladuj_grafiki();
    uzyj_regex(indeksy_x, indeksy_y, kordynaty_x, kordynaty_y);
    srand(time(NULL));
    tablica tablica_1;
    sf::Texture texture;
    texture.loadFromFile(to_string(3) + ".png");
    sf::Sprite obrazek;
    sf::Sprite cokolwiek;
    obrazek.setTexture(texture);
    std::vector<sf::Texture> pola;
    bool wygrana = false;
    int menu = 0;
    int zapisanie = 0;
    Nick pseudonim;
    logi czasy_i_nazwy;
    save zapis;
    czasy_i_nazwy.set_sciezka("Logi");
    czasy_i_nazwy.set_nazwa("21.32.33", "kloda");
    czasy_i_nazwy.wstaw_do_folderu();
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) 
    {
        std::cerr << "Error loading font\n";
        return -1;
    }
    sf::Text instructions("Wprowadź swój 5-znakowy nick:", font, 24);
    instructions.setPosition(100, 100);
    string nickname;
    sf::Text nicknameText("", font, 24);
    nicknameText.setPosition(100, 200);
    sf::Text clockText("", font, 24);
    clockText.setPosition(270, 440);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "3072");
    window.setFramerateLimit(60);
    
    tablica_1.start();
    
    bool wprowadzono_nick = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (!wprowadzono_nick) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        char entered = static_cast<char>(event.text.unicode);
                        if (std::isalnum(entered)) {
                            if (nickname.length() < 5) {
                                nickname += entered;
                            }
                        }
                        else if (entered == '\b' && !nickname.empty()) {
                            nickname.pop_back();
                        }
                    }
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter && nickname.length() == 5) {
                        std::cout << "Nickname entered: " << nickname << std::endl;
                        pseudonim.set_nick(nickname);
                        wprowadzono_nick = true;
                        zegar.start();
                    }
                }
            }
            else {
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::W:
                        tablica_1.W_wgore();
                        std::cout << "W pressed: Moving up" << std::endl;
                        break;
                    case sf::Keyboard::A:
                        tablica_1.A_wlewo();
                        std::cout << "A pressed: Moving left" << std::endl;
                        break;
                    case sf::Keyboard::D:
                        tablica_1.D_wprawo();
                        std::cout << "D pressed: Moving right" << std::endl;
                        break;
                    case sf::Keyboard::S:
                        tablica_1.S_wdol();
                        std::cout << "S pressed: Moving down" << std::endl;
                        break;
                    case sf::Keyboard::Backspace:
                        tablica_1.powrot();
                        std::cout << "BcSp pressed: reversing move" << std::endl;
                        break;
                    case sf::Keyboard::R:
                        tablica_1.start();
                        std::cout << "R pressed: reseting game" << std::endl;
                        break;
                    case sf::Keyboard::Z:
                        zapis.zapisz("saves.txt",tablica_1.plansza, pseudonim.nick);
                        std::cout << "Z pressed: saving board" << std::endl;
                        break;
                    case sf::Keyboard::X:
                        zapis.odczytaj("saves.txt", tablica_1.plansza, pseudonim.nick);
                        std::cout << "X pressed: loading saves" << std::endl;
                        break;
                    default:
                        break;
                    }
                }
            }
        }


        window.clear();

        if (!wprowadzono_nick) 
        {
            nicknameText.setString(nickname);
            window.draw(instructions);
            window.draw(nicknameText);
        }
        else 
        {
            pola.clear();
            rysuj(tablica_1.plansza, indeksy_x, indeksy_y, kordynaty_x, kordynaty_y, do_gry.obrazy, pola);
            for (int i = 0; i < 16; i++) {
                cokolwiek.setTexture(pola[i]);
                cokolwiek.setPosition(kordynaty_x[i], kordynaty_y[i]);
                window.draw(cokolwiek);
            }
        }
        clockText.setString("Time: " + zegar.getElapsedTime());
        window.draw(clockText);
        window.display();


        if (tablica_1.sprawdz_koniec(wygrana) == true) {
            if (zapisanie == 0)
            {
                std::cout << "gra uznała, że koniec";
                czasy_i_nazwy.set_sciezka("Logi");
                czasy_i_nazwy.set_nazwa(zegar.getElapsedTime(), pseudonim.get_nick());
                czasy_i_nazwy.zamien_znaki();
                czasy_i_nazwy.wstaw_do_folderu();
                zegar.stop();
                break;
            }
        }
    }
    return 0;
}