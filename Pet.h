#ifndef PET_H
#define PET_H
#include <fstream>
#include <string>
#include <iostream>

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

    int cleanliness = 80; // czystosc 0-100
    bool isSick = false;  // czy zwierzak jest chory

    // ogarnia brud i szanse na chorobe w trakcie tury
    void updateHygieneAndHealth();

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
    virtual void clean(); // wirtualne bo kazdy zwierzak inaczej reaguje na kapiel
    void heal();          // podanie lekarstwa na chorobe
    //przeciazenie += daje bonus do szczescia np za poglaskanie
    Pet& operator+=(int bonusHappiness);



    //przeciazenie ++ symuluje uplyw 1 tury dla zwierzaka
    Pet& operator++();


    // przeciazenie << pozwala wypisac zwierzaka przez std::cout << *playerPet
    friend std::ostream& operator<<(std::ostream& os, const Pet& pet);
};


#endif 