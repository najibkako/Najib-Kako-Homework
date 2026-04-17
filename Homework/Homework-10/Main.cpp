#include <iostream>
#include <string>
using namespace std;

class Pokemon {
protected: 
    int level;

public:
    Pokemon(int lvl) {
        level = lvl;
    }

    void attack() {
        cout << "the little shit attacked!" << endl;
    } 

    void type() {
        cout << "type unknown" << endl; 

    }
};

class ElectricPokemon : public Pokemon {
    public:
    
        ElectricPokemon(int lvl) : Pokemon(lvl) {}

        void type() {
            cout << "Electric type" << endl;
        }
};

class Pikachu : public ElectricPokemon { 
    public:
        Pikachu(int lvl) : ElectricPokemon(lvl) {}

        void attack() {
            cout << "pikachu uses Thunderbolt" << endl;

        }

        int main() {
            Pikachu pikachu(10);
            pikachu.Type();
            pikachu.attack();

            return 0;

        }
}