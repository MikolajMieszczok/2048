#pragma once
#include <vector>
using namespace std;
class tablica
{
public:
    std::vector<int>pola;
    std::vector<vector<int>>plansza;
    std::vector<vector<int>>new_plansza;
    void start()
    {
        plansza.clear();
        for (int i = 0; i < 4; i++)
        {
            pola.push_back(0);
        }
        for (int i = 0; i < 4; i++)
        {
            plansza.push_back(pola);
        }
        wstaw();
        wstaw();
    }
    void wstaw()
    {
        while (true)
        {
            int x = rand() % 4;
            int y = rand() % 4;
            if (plansza[x][y] == 0)
            {
                plansza[x][y] = 3;
                break;
            }
        }
    }
    void powrot()
    {
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                plansza[i][j] = new_plansza[i][j];
            }
        }
    }
    bool sprawdz_koniec(bool& wygrana)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (plansza[i][j] == 0)
                {
                    return false;
                }
                if (plansza[i][j] == 3072)
                {
                    wygrana = true;
                }
                if (j < 3 && plansza[i][j] == plansza[i][j + 1]) return false;
                if (i < 3 && plansza[i][j] == plansza[i + 1][j]) return false;
            }
        }
        wygrana = true;
        return true;

    }
    void wyswietl()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << plansza[i][j] << " ";
            }
            std::cout << endl;
        }
        std::cout << endl;
    }
    void slideAndMerge(vector<int>& col) {
        int n = col.size();
        for (int i = n - 1; i > 0; --i) {
            if (col[i] == 0) {
                for (int j = i - 1; j >= 0; --j) {
                    if (col[j] != 0) {
                        col[i] = col[j];
                        col[j] = 0;
                        break;
                    }
                }
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (col[i] != 0 && col[i] == col[i - 1]) {
                col[i] *= 2;
                col[i - 1] = 0;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (col[i] == 0) {
                for (int j = i - 1; j >= 0; --j) {
                    if (col[j] != 0) {
                        col[i] = col[j];
                        col[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    void D_wprawo() {
        bool zmiana;
        zmiana = false;
        std::vector<int>pola_new_pla;
        new_plansza.clear();
        for (int i = 0; i < 4; i++)
        {
            pola_new_pla.push_back(0);
        }
        for (int i = 0; i < 4; i++)
        {
            new_plansza.push_back(pola);
        }
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                new_plansza[i][j] = plansza[i][j];
            }
        }
        rotateClockwise();
        for (int i = 0; i < 4; ++i) {
            std::vector<int> col(4);
            for (int j = 0; j < 4; ++j) col[j] = plansza[j][i];
            slideAndMerge(col);
            for (int j = 0; j < 4; ++j) plansza[j][i] = col[j];
        }
        rotateCounterClockwise();
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                if (new_plansza[i][j] != plansza[i][j])
                    zmiana = true;
            }
        }
        if (zmiana == true)
        {
            wstaw();
        }
    }
    void A_wlewo() {
        bool zmiana;
        zmiana = false;
        std::vector<int>pola_new_pla;
        new_plansza.clear();
        for (int i = 0; i < 4; i++)
        {
            pola_new_pla.push_back(0);
        }
        for (int i = 0; i < 4; i++)
        {
            new_plansza.push_back(pola);
        }
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                new_plansza[i][j] = plansza[i][j];
            }
        }
        rotateClockwise();
        rotateClockwise();
        rotateClockwise();
        for (int i = 0; i < 4; ++i) {
            std::vector<int> col(4);
            for (int j = 0; j < 4; ++j) col[j] = plansza[j][i];
            slideAndMerge(col);
            for (int j = 0; j < 4; ++j) plansza[j][i] = col[j];
        }
        rotateClockwise();
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                if (new_plansza[i][j] != plansza[i][j])
                    zmiana = true;
            }
        }
        if (zmiana == true)
        {
            wstaw();
        }
    }

    void W_wgore() {
        bool zmiana;
        zmiana = false;
        std::vector<int>pola_new_pla;
        new_plansza.clear();
        for (int i = 0; i < 4; i++)
        {
            pola_new_pla.push_back(0);
        }
        for (int i = 0; i < 4; i++)
        {
            new_plansza.push_back(pola);
        }
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                new_plansza[i][j] = plansza[i][j];
            }
        }
        rotateClockwise();
        rotateClockwise();
        for (int i = 0; i < 4; ++i) {
            vector<int> col(4);
            for (int j = 0; j < 4; ++j) col[j] = plansza[j][i];
            slideAndMerge(col);
            for (int j = 0; j < 4; ++j) plansza[j][i] = col[j];
        }
        rotateClockwise();
        rotateClockwise();
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                if (new_plansza[i][j] != plansza[i][j])
                    zmiana = true;
            }
        }
        if (zmiana == true)
        {
            wstaw();
        }
    }

    void S_wdol() {
        bool zmiana;
        zmiana = false;
        std::vector<int>pola_new_pla;
        new_plansza.clear();
        for (int i = 0; i < 4; i++)
        {
            pola_new_pla.push_back(0);
        }
        for (int i = 0; i < 4; i++)
        {
            new_plansza.push_back(pola);
        }
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                new_plansza[i][j] = plansza[i][j];
            }
        }
        for (int i = 0; i < 4; ++i) {
            std::vector<int> col(4);
            for (int j = 0; j < 4; ++j) col[j] = plansza[j][i];
            slideAndMerge(col);
            for (int j = 0; j < 4; ++j) plansza[j][i] = col[j];
        }
        for (int i = 0; i < plansza.size(); i++)
        {
            for (int j = 0; j < plansza.size(); j++)
            {
                if(new_plansza[i][j] != plansza[i][j])
                    zmiana = true;
            }
        }
        if (zmiana == true)
        {
            wstaw();
        }
    }

    void rotateClockwise() {
        std::vector<std::vector<int>> newPlansza(4, std::vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newPlansza[j][3 - i] = plansza[i][j];
            }
        }
        plansza = newPlansza;
    }

    void rotateCounterClockwise() {
        std::vector<std::vector<int>> newPlansza(4, std::vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                newPlansza[3 - j][i] = plansza[i][j];
            }
        }
        plansza = newPlansza;
    }
};