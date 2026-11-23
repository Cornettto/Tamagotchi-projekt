#ifndef PET_H
#define PET_H
#include <fstream>
#include <string>

class Pet {
protected:
    std::string name;
    int hunger;      // 0 (najedzony) - 100 (glodny)
    int happiness;   // 0 (smutny) - 100 (happy)
    int energy;      // 0 (niewyspany) - 100 (wyspany)
    bool isAlive;
    int ageTurns = 0; // ile tur zwierzak juz przezyl
    //  pilnujaca zakresu 0-100 
    void clampStats();

public:
    Pet(const std::string& petName);
    virtual ~Pet() = default;
    std::string getStage() const; // zwraca etap zycia

    // interakcje 
    virtual void feed();
    virtual void play();
    virtual void sleep();

    // symulacja uplywu czasu (wywolywana co ture)
    virtual void update();

    // to chb zle
    virtual void makeSound() const = 0;
    virtual std::string getSpecies() const = 0;

    //  wyswietlanie stanu ziomka
    std::string getName() const { return name; }
    int getHunger() const { return hunger; }
    int getHappiness() const { return happiness; }
    int getEnergy() const { return energy; }
    bool checkIsAlive() const { return isAlive; }
    void modifyStats(int dHunger, int dHappiness, int dEnergy);
    
    void saveToFile(std::ofstream& file) const;// zapis i odczyt statystyk z pliku
    void loadFromFile(std::ifstream& file);
    void drawFace() const; // rysuje mordke zwierzaka zaleznie od statystyk

};

#endif 