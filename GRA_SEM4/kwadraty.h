#pragma once
#include "grafiki.h"
class kwadrat : public grafiki
{
public:
    friend grafiki;
    int indeks_obrazu = 0;
    sf::Texture square = obrazy[indeks_obrazu];
    int value = 3;
    void rank_up()
    {
        value = 2 * value;
        square = obrazy[indeks_obrazu++];
    }
};