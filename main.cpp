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


using namespace std;

int rounds = 5;
int lettersCount = 10;
int maxShuffles = 2;

const int MAX_TRIES = 3;
const char WRONG_INPUT_MSG[] = "Wrong input! Try again...";
const int MIN_ROUNDS = 3;
const int MAX_ROUNDS = 9;

//include headers after constants in order to use them
#include "helpers.h"
#include "dictionaryController.h"
#include "settingsController.h"


void mainMenu();

void game();

void settingsMenu();

void changeRoundsMenu();

int main() {
    mainMenu();

    return 0;
}

void mainMenu() {
    ostringstream welcomeMsgs;

    welcomeMsgs << "Welcome to my scrabble game!" << endl << endl;
    welcomeMsgs << "Choose one of the following options by typing 1, 2, 3 or 4..." << endl;
    welcomeMsgs << "1. Start new game" << endl;
    welcomeMsgs << "2. Settings" << endl;
    welcomeMsgs << "3. Add new word" << endl;
    welcomeMsgs << "4. Exit" << endl;

    cout << welcomeMsgs.str();

    string input;
    bool ok = false;
    while (!ok) {
        ok = true;

        cin >> input;
        if (!isValidCommand(input)) {
            ok = false;
            cout << WRONG_INPUT_MSG << endl;
            continue; //if the input is not real command, we go again to line 56 with ok = false
        }

        int command = toNumber(input[0]);

        switch (command) {
            case 1:
                game();
                break;
            case 2:
                settingsMenu();
                break;
            case 3:
                break;
            case 4:
                cout << "bye bye :)";
                return;
            default:
                ok = false;
                cout << WRONG_INPUT_MSG << endl;
        }
    }
}

void game() {
    int points = 0;
    int remainingShuffles = maxShuffles;

    for (int i = 0; i < rounds; ++i) {
        cout << "Round # " << i + 1 << ". Available letters: ";

        char *letters = generateLetters(lettersCount);
        printLetters(letters, lettersCount); // print the letters which the user can use to make a word

        int remainingTries = MAX_TRIES;
        string word;
        while (remainingTries > 0) {
            cin >> word;

            if (word == "0") { //Shuffle
                if (remainingShuffles == 0) {
                    cout << "No remaining shuffles! Continue with the same letters:" << endl;
                } else {
                    letters = generateLetters(lettersCount);

                    cout << "Remaining shuffles: " << --remainingShuffles << endl;
                    cout << "New letters: ";
                }

                printLetters(letters, lettersCount);

                continue;
            }

            //check if the word can be made from this letters
            bool isPossible = isPossibleWord(word, letters, lettersCount);
            if (!isPossible || !isRealWord(word)) { //if it is not possible, or it is not in the dictionary
                remainingTries--;

                if (!isPossible) {
                    cout << "Invalid combination. You cannot make this word from the given letters." << endl;
                    cout << "Remaining tries: " << remainingTries << endl;
                } else {
                    cout << "This word is not in my dictionary. Remaining tries: " << remainingTries << endl;
                }

                if (remainingTries == 0) break;
                cout << "Try again with: ";
                printLetters(letters, lettersCount);
            } else {
                points += word.size();

                if (i != rounds - 1) // if it is not the last round
                    cout << "Your points so far are: " << points << endl;

                break;
            }
        }
    }

    cout << "Congrats! You reached the end of the game. Your total points are: " << points << endl;
    cout << "0. End game" << endl;
    cout << "1. Return to menu" << endl;

    int command;
    cin >> command;

    if (command == 0) return;

    mainMenu();
}

void settingsMenu() {
    ostringstream settingsMenu;
    settingsMenu << "Choose what do you want to change (1, 2, 3) or go back (4): " << endl;
    settingsMenu << "1. Number of rounds" << endl;
    settingsMenu << "2. Number of the given letters" << endl;
    settingsMenu << "3. Number of allowed shuffles for the whole game" << endl;
    settingsMenu << "4. Back to main menu" << endl;

    cout << settingsMenu.str();

    string input;

    bool ok = false;
    while (!ok) {
        ok = true;

        cin >> input;
        if (!isValidCommand(input)) { //ine number between 0-9
            ok = false;
            cout << WRONG_INPUT_MSG << endl;
            continue; //if the input is not real command, we go again to line 56 with ok = false
        }

        int command = toNumber(input[0]);

        switch (command) {
            case 1:
                changeRoundsMenu();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                mainMenu();
                break;
            default:
                ok = false;
                cout << WRONG_INPUT_MSG << endl;
        }
    }
}

void changeRoundsMenu() {
    ostringstream menu;
    menu << "Choose the number of rounds (3-9) or type 0 to go back." << endl;

    cout << menu.str();

    string input;
    cin >> input;

    if (!isValidCommand(input)) {
        cout << WRONG_INPUT_MSG << endl;
        return changeRoundsMenu();
    }

    int command = toNumber(input[0]);

    if (command == 0) {
        settingsMenu();
    } else if (command >= 3 && command <= 9) {
        rounds = command; //change the rounds
        cout << "Rounds set to " << rounds << " successfully!" << endl;
        cout << "Returning to settings..." << endl;
        settingsMenu();
    } else {
        cout << WRONG_INPUT_MSG << endl;
        return changeRoundsMenu();
    }
}