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

using namespace std;

const int ENGLISH_LETTERS = 26;

bool isNumber(char a) {
    return a - '0' <= 9 && a - '0' >= 0;
}

int toNumber(char a) {
    return a - '0';
}

char randomLetter() {
    int random = rand() % ENGLISH_LETTERS;

    return (char) (random + (int) 'a');
}

char *generateLetters(int lettersCount) {
    char *result = new char[lettersCount];

    for (int i = 0; i < lettersCount; ++i) {
        result[i] = randomLetter();
    }
    return result;
}

void printLetters(const char *letters, int size) {
    for (int i = 0; i < size; ++i) {
        cout << letters[i] << ' ';
    }
    cout << endl;
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

bool isPossibleWord(const string word, const char *letters, int lettersCount) {
    int *lettersArr = getLettersArray(letters, lettersCount);

    for(const char& letter : word) { //for every letter in the word
        if (lettersArr[letter - 'a'] == 0) //if on the position of the current letter we do not have given letters
            return false;
        lettersArr[letter - 'a']--;
    }
    return true;
}