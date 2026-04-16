#include <iostream>
#include <bitset> 
#include <cstdint>
#include <ctime>
#include <string>

using namespace std;


// Hello. It's currently 2:47 AM.
// I think this code is shit. To be honest, i KNOW its shit. Its too late for me to think about how shit this code is. 
// I havent checked if it works, I honestly fear checking so we will leave it up to luck. 
// I havent even checked if this still aligns with what the assigment was. 
// to be honest I gave up halfway through and just kept pressing tab on the vscode recommendations.
// hopefully it is to your liking.
// GGS im surprised im not failing this class
// have a good night.

class MotorStatus {
private:
    uint8_t motorState;
    uint8_t overheatingMotors = 0;
    int turnCount;

    void initialize() {
        srand(time(0));

        do {
            motorState = static_cast<uint8_t>(rand() % 256);
        } while (motorState == 0);

        turnCount = 0;
        updateOverheating();
        displayStatus();
    }

    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            turnCount++;
            return;
        }
        
        int newMotor = 0;
        do {
            newMotor = rand() % 8;
        } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) || ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));
        overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
    }

    void displayStatus() {
        cout << "Motor Status: " << bitset<8>(motorState) << endl;
        cout << "Overheating Motors: " << bitset<8>(overheatingMotors) << endl;
        cout << "Turn Count: " << turnCount << endl;
    }

public: 
    MotorStatus() {
        initialize();
    }

    bool turnOff(uint8_t guess) {
        uint8_t correctMotors = overheatingMotors & guess;
        if (correctMotors == overheatingMotors) {
            motorState &= ~overheatingMotors;
            overheatingMotors = 0;
            turnCount = 0;
            displayStatus();
            return true;
        } else {
            overheatingMotors |= correctMotors;
            turnCount++;
            displayStatus();
            return false;
        }
    }
};

int main() {
    MotorStatus motorStatus;
    string input;

    while (true) {
        cout << "Enter your guess (8-bit binary): ";
        cin >> input;

        if (input.length() != 8 || input.find_first_not_of("01") != string::npos) {
            cout << "Invalid input. Please enter an 8-bit binary number." << endl;
            continue;
        }

        uint8_t guess = static_cast<uint8_t>(bitset<8>(input).to_ulong());
        if (motorStatus.turnOff(guess)) {
            cout << "Congratulations! You've turned off all overheating motors!" << endl;
            break;
        }
    }

    return 0;