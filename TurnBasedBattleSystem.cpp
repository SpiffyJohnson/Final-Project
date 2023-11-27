// Link command: g++ -o main.exe Monster.cpp "TurnBasedBattleSystem.cpp"
// Run in the Command Prompt in the folder containing the "Monster.h", "Monster.cpp", and "TurnBasedBattleSystem.cpp" files.

#include "Monster.h"
#include <iostream>
#include <fstream>

using namespace std;

int const AMOUNT_OF_MONSTERS = 18;                              // The amount of monsters in the game.
string QUIT = "99";                                             // Used to quit the game when asked.
string UserInput = "";                                          // Used to decide what action to take in the menus.
string Line = "---------------------------------------";        // Used to separate output.
Monster ArrayOfMonsters[AMOUNT_OF_MONSTERS];                    // An array of Monster objects.

// ---------------------------------------------------------------------- Function Prototypes:

void FillArrayOfMonsterObjects(); 

// ---------------------------------------------------------------------- Main Program:

int main() {
    FillArrayOfMonsterObjects();
    while (1 == 1) {
        cout << "Please enter a monster's ID number (or '" << QUIT << "' to quit): ";
        cin >> UserInput;
        if (UserInput == QUIT) {
            break;
        } else {
            cout << Line << endl;
            ArrayOfMonsters[stoi(UserInput) - 1].PrintInfo();
            cout << Line << endl;
        }
    }
    cout << "Press Enter to exit...";
    cin.get();  // Wait for the user to press Enter
    return 0;
}

// ---------------------------------------------------------------------- Function Definitions:

// Opens the "MonsterData.txt" file and reads it into ArrayOfMonsters objects.
void FillArrayOfMonsterObjects() {
    ifstream File("MonsterData.txt");
    string Text = "";
    for (int i = 0; i < AMOUNT_OF_MONSTERS; i++) {
        File >> Text;
        ArrayOfMonsters[i].SetName(Text);
        File >> Text;
        ArrayOfMonsters[i].SetHP(Text);
        File >> Text;
        ArrayOfMonsters[i].SetATK(Text);
        File >> Text;
        ArrayOfMonsters[i].SetDEF(Text);
        File >> Text;
        ArrayOfMonsters[i].SetAG(Text);
        File >> Text;
        ArrayOfMonsters[i].SetEXP(Text);
        File >> Text;
        ArrayOfMonsters[i].SetMethodOfAttack(Text);
    }
    File.close();
}
