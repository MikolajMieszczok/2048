class save
{
public:
    void zapisz(std::string plik_nazwa, std::vector<std::vector<int>> tablica, std::string gracz_nazwa) {
        std::ofstream outfile(plik_nazwa, std::ios_base::app);
        if (!outfile.is_open()) {
            std::cerr << "Error: Unable to open file for writing: " << plik_nazwa << std::endl;
            return;
        }
        outfile << gracz_nazwa << " ";
        for (int i = 0; i < tablica.size(); ++i) {
            for (int j = 0; j < tablica[i].size(); ++j) {
                outfile << tablica[i][j] << " ";
            }
        }
        outfile << std::endl;
        outfile.close();
    }

    void odczytaj(std::string plik_nazwa, std::vector<std::vector<int>>& tablica, std::string gracz_nazwa)
    {
        std::ifstream infile(plik_nazwa);
        std::string line;
        std::string imie, plan;
        std::vector<std::string> imiona;
        std::vector<int> plansze;
        std::vector<std::vector<int>> plansze_potega;
        int liczba;
        int index_plansze_potega = 0;
        int index_gracza = -1;

        while (std::getline(infile, line)) {
            imie = "";
            plan = "";
            plansze.clear();
            std::istringstream iss(line);
            iss >> imie;
            std::getline(iss, plan);
            std::istringstream iss2(plan);
            while (iss2 >> liczba)
            {
                plansze.push_back(liczba);
            }
            imiona.push_back(imie);
            plansze_potega.push_back(plansze);
            if (imie == gracz_nazwa)
            {
                index_gracza = imiona.size() - 1;
            }
        }
        if (index_gracza != -1)
        {
            index_plansze_potega = 0;
            for (int i = 0; i < tablica.size(); i++)
            {
                for (int j = 0; j < tablica[i].size(); j++)
                {
                    tablica[i][j] = plansze_potega[index_gracza][index_plansze_potega];
                    index_plansze_potega++;
                }
            }
        }
        else
        {
            std::cout << "nie znaleziono gracza o takiej nazwie" << std::endl;
        }
    }
};