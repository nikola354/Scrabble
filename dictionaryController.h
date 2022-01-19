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
* <files for actions with the dictionary>
*
*/

#ifndef SCRABBLE_DICTIONARYCONTROLLER_H
#define SCRABBLE_DICTIONARYCONTROLLER_H

#endif //SCRABBLE_DICTIONARYCONTROLLER_H

#include <fstream>

const char path[] = "../words.txt";

bool isRealWord(string word) {
    fstream dictionary;

    dictionary.open(path, fstream::in);
    if (!dictionary.is_open()) {
        std::cout << "System error! Could not open dictionary!" << endl;
        return false;
    }

    string vocabulary;
    while (getline(dictionary, vocabulary)) {
        if (word == vocabulary) {
            dictionary.close();
            return true;
        }
    }

    dictionary.close();
    return false;

}