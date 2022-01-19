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
* <file with helper functions>
*
*/

#ifndef SCRABBLE_HELPERS_H
#define SCRABBLE_HELPERS_H
#endif

#include <stdlib.h>
#include<time.h>

using namespace std;

const int ENGLISH_LETTERS = 26;
//for each letter in the alphabet (0-25) we have different point, depending on how difficult is to form a word using that letter:
const int lettersPoints[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1,
        8, 5, 1, 3, 1, 1, 3, 10,
        1, 1, 1, 1, 4, 4, 8, 4, 10
};

bool isDigit(char a) {
    return a - '0' <= 9 && a - '0' >= 0;
}

bool isNumber(const string &str) {
    for (char const &c: str) {
        if (!isDigit(c)) return false;
    }
    return true;
}

char randomLetter() {
    int random = rand() % ENGLISH_LETTERS;

    return (char) (random + (int) 'a');
}

char *generateLetters(int lettersCount) {
    char *result = new char[lettersCount];

    for (int i = 0; i < lettersCount; ++i) {
        srand(i + time(0)); //every time we get 10 different letters
        result[i] = randomLetter();
    }
    return result;
}

void printLetters(const char *letters, int size) {
    for (int i = 0; i < size; ++i) {
        cout << letters[i] << ' ';
    }
    cout << endl;
    cout << "Try with word or type 1 for new letters or 0 to end the game:" << endl;
}

int *getLettersArray(const char *letters, int lettersCount) {
    int *arr = new int[ENGLISH_LETTERS];

    for (int i = 0; i < ENGLISH_LETTERS; ++i) {
        arr[i] = 0;
    }

    for (int i = 0; i < lettersCount; ++i) {
        arr[letters[i] - 'a']++;
    }
    return arr;
}

bool isLowerLetter(const char a) {
    return a >= 'a' && a <= 'z';
}

bool isWord(const string &word) {
    for (char const &c: word) {
        if (!isLowerLetter(c)) return false;
    }

    return true;
}

bool isPossibleWord(const string &word, const char *letters, int lettersCount) {
    if (!isWord(word)) return false; //if it is not a word at all (contains numbers or special chars)

    int *lettersArr = getLettersArray(letters, lettersCount);

    for (const char &letter: word) { //for every letter in the word
        if (lettersArr[letter - 'a'] == 0) //if on the position of the current letter we do not have given letters
            return false;
        lettersArr[letter - 'a']--;
    }
    return true;
}

int getPoints (char a) {
    return lettersPoints[a - 'a'];
}

int calculatePoints (const string &word){
    int sum = 0;
    for(const char &c : word){
        cout << c << " -> " << getPoints(c) << endl;
        sum += getPoints(c);
    }
    return sum;
}