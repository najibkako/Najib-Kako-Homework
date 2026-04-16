#include <iostream>
#include <string>
using namespace std;

class Rock {
    public:
        void attack() {
            cout << "u hit the rock.." << endl;
            cout << "why r u hitting a rock tho???" << endl;
        }

        void attack(int damage) {
            cout << "u hit the rock for " << damage << " damage.." << endl;
            cout << "why r u hitting a rock tho???" << endl;
        }

        void attack(string spell, int damage) {
            cout << "u hit rock with " << spell << " for " << damage << " damage.." << endl;
            cout << "why r u using a spell on a rock tho???" << endl;
        }
};

int main() {
        Rock r;
        r.attack();
        r.attack(10);
        r.attack("fireball", 20);

        return 0;
}

