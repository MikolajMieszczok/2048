#pragma once
//u¿ycie filesystem
class logi
{
public:
    std::string nazwa;
    std::string sciezka_przejsciowa;
    std::filesystem::path sciezka;

    void get_nazwa() const
    {
        std::cout << nazwa;
    }

    void set_nazwa(const std::string& czas, const std::string& nick)
    {
        nazwa = czas + " by " + nick;
    }

    void wstaw_do_folderu()
    {
        sciezka = std::filesystem::path(sciezka_przejsciowa) / nazwa;
        std::ofstream outFile(sciezka);
        if (outFile) {
            outFile << "Log entry: " << nazwa << std::endl;
            outFile.close();
            std::cout << "File created successfully: " << sciezka << std::endl;
        }
        else {
            std::cerr << "Error creating file: " << sciezka << std::endl;
        }
    }

    void set_sciezka(const std::string& x)
    {
        sciezka_przejsciowa = x;
    }
    void zamien_znaki() {
        std::ranges::replace(nazwa, ':', '.');
    }

};