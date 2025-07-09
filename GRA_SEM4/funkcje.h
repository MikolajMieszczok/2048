#pragma once
void rysuj(vector<vector<int>>& x, vector<int>& ix, vector<int>& iy, vector<int>& kx, vector<int>& ky, vector<sf::Texture>obrazy, vector<sf::Texture>& pola)
{
    for (int i = 0; i < 16; i++)
    {
        sf::Texture texture;
        sf::Sprite sprite;
        if (!texture.loadFromFile(to_string(x[iy[i] - 1][ix[i] - 1]) + ".png"))
        {
            std::cout << "nie udalo sie zaladowac pliku";
        }
        sprite.setTexture(texture);
        pola.push_back(texture);
    }
}
void uzyj_regex(vector<int>& ix, vector<int>& iy, vector<int>& kx, vector<int>& ky)
{
    std::ifstream file("regex.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
    }
    std::string line;
    std::regex pattern(R"((\d)\.(\d) - \((\d+), (\d+)\))");
    std::smatch match;

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, pattern)) {
            if (match.size() == 5) { 
                std::string first = match[1].str();
                std::string second = match[2].str();
                std::string x = match[3].str();
                std::string y = match[4].str();
                int valix = std::stoi(first); 
                int valiy = std::stoi(second);
                int valkx = std::stoi(x);
                int valky = std::stoi(y);
                ix.push_back(valix);
                iy.push_back(valiy);
                kx.push_back(valkx);
                ky.push_back(valky);
            }
        }
    }
    file.close();
}