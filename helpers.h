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


char randomLetter() {
    int random = rand() % 26;

    return (char) (random + (int) 'a');
}

bool isNumber(char a) {
    return a - '0' <= 9 && a - '0' >= 0;
}

int toNumber(char a){
    return a - '0';
}