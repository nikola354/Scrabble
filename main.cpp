/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @compiler GCC
*
* <main file>
*
*/

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "helpers.h"

using namespace std;

int rounds = 5;
int lettersCount = 10;

void loadMenu();

void game();

int main() {
    loadMenu();

    return 0;
}

void loadMenu() {
    ostringstream welcomeMsgs;

    welcomeMsgs << "Welcome to my scrabble game!" << endl << endl;
    welcomeMsgs << "Choose one of the following options by typing 1, 2, 3 or 4..." << endl;
    welcomeMsgs << "1. Start new game" << endl;
    welcomeMsgs << "2. Settings" << endl;
    welcomeMsgs << "3. Add new word" << endl;
    welcomeMsgs << "4. Exit" << endl;

    cout << welcomeMsgs.str();

    ostringstream wrongInputMsgs;
    wrongInputMsgs << "Wrong input! Try again..." << endl;

    char input;
    bool ok = false;
    while (!ok) {
        ok = true;

//        cin >> input;
        input = '1';
        if (!isNumber(input) || toNumber(input) > 4 || toNumber(input) < 1) {
            ok = false;
            cout << wrongInputMsgs.str();
            continue;
        }

        int command = toNumber(input);

        switch (command) {
            case 1:
                game();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "bye bye :)";
                return;
        }
    }
}

void game() {
    for (int i = 0; i < rounds; ++i) {
        cout << "Round # " << i + 1 << ". Available letters: ";

        char *letters = generateLetters(lettersCount);
        printLetters(letters, lettersCount);

        string word;
        cin >> word;

        if (!isPossibleWord(word, letters, lettersCount)){
            cout << "Invalid word.";
        }

        break;
    }
}