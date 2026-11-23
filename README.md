# Konsolowe Tamagotchi (C++)

Projekt zaliczeniowy z przedmiotu **Języki Obiektowe**. Jest to konsolowa gra symulacyjna Tamagotchi polegająca na opiece nad wirtualnym zwierzakiem.

## Zastosowane mechanizmy programowania obiektowego (OOP)

* **Abstrakcja:** Klasa bazowa `Pet` jest klasą abstrakcyjną posiadającą metody czysto wirtualne (`makeSound()`, `getSpecies()`), co uniemożliwia utworzenie ogólnego obiektu zwierzaka i wymusza implementację tych metod w klasach pochodnych.
* **Dziedziczenie:** 12 klas pochodnych (`Dog`, `Cat`, `Spider`, `Hamster`, `Pigeon`, `Snake`, `Snail`, `Turtle`, `Fish`, `Rabbit`, `Anteater`, `Gecko`) dziedziczy po klasie `Pet`.
* **Polimorfizm:** Obiekt zwierzaka przechowywany jest w klasie `Game` za pomocą inteligentnego wskaznika `std::unique_ptr<Pet>`. Wywołania metod takich jak `feed()`, `play()`, `sleep()` czy `update()` są dynamicznie wiązane w czasie działania programu (nadpisywanie metod za pomocą `override`).
* **Hermetyzacja (Enkapsulacja):** Statystyki zwierzaka (`hunger`, `happiness`, `energy`, `isAlive`, `ageTurns`) są chronione (`protected`), a ich modyfikacja odbywa się wyłącznie przez kontrolowane metody klasy `Pet` z automatycznym pilnowaniem zakresu `0-100` (`clampStats()`).
* **Separacja odpowiedzialności (SRP):** Logika domenowa zwierzaków (`Pet` i klasy pochodne) jest oddzielona od pętli gry, obsługi menu i wejścia/wyjścia konsoli (`Game`).

## Dostępne gatunki zwierzaków

Każdy gatunek posiada unikalne komunikaty oraz zmodyfikowaną mechanikę rozgrywki (inne tempo spadku statystyk lub reakcje na akcje):
1. **Pies (`Dog`)** – bardziej cieszy się z zabawy.
2. **Kot (`Cat`)** – w 50% przypadków ignoruje próbę zabawy, wolniej się męczy.
3. **Pająk (`Spider`)** – bardzo wolny metabolizm, małe zapotrzebowanie na zabawę.
4. **Chomik (`Hamster`)** – duży przyrost szczęścia w kołowrotku, ale szybkie zużycie energii.
5. **Gołąb (`Pigeon`)** – zyskuje szczęscie podczas jedzenia.
6. **Wąż (`Snake`)** – rzadsze, ale bardzo sycące karmienie; powolny spadek statystyk.
7. **Ślimak (`Snail`)** – minimalny koszt energii podczas zabawy, mocna regeneracja podczas snu.
8. **Żółw (`Turtle`)** – bardzo wolne starzenie się i spadek statystyk co turę.
9. **Ryba (`Fish`)** – specyficzne interakcje akwariowe.
10. **Królik (`Rabbit`)** – wysoka aktywność i premia do humoru przy karmieniu.
11. **Mrówkojad (`Anteater`)** – duże zbicie głodu przy karmieniu, szybsze pojawianie się głodu co turę.
12. **Gekon (`Gecko`)** – wysoka regeneracja energii podczas wygrzewania się.

## Funkcjonalności gry

* **System statystyk i etapów życia:** Śledzenie głodu, szczęścia i energii w przedziale `0-100` oraz dorastanie zwierzaka wraz z liczbą przetrwanych tur (*Maluch* → *Nastolatek* → *Dorosły* → *Stary*).
* **Dynamiczny ASCII Art:** Wyświetlanie miny zwierzaka w konsoli zależnie od jego aktualnego stanu (głód, zmęczenie, radość, smutek).
* **Zdarzenia losowe:** System losowych wydarzeń między turami wplywających na statystyki zwierzaka (z zabezpieczeniem gwarantującym wystąpienie zdarzenia maksymalnie co 4 tury).
* **Mini-gra w kubki:** Dodatkowy tryb zgadywania kubka ze smakołykiem.
* **Zapis stanu gry:** Możliwość zapisania aktualnego gatunku, imienia oraz statystyk zwierzaka do pliku `save.txt`.

## Wymagania i uruchomienie

Projekt wymaga kompilatora obsługującego standard **C++17** (ze względu na użycie `std::clamp`).

Kompilacja i uruchomienie z poziomu terminala (GCC / MinGW):
```bash
g++ -std=c++17 *.cpp -o tamagotchi.exe
./tamagotchi.exe