#include "task1.h"


void outputCommonChars(char unique1[], char unique2[]);

void task1() {
    char trash[1];
    std::cin.getline(trash, 1, '\n');

    char input1[100] = {'\0'};
    char input2[100] = {'\0'};

    char unique1[100] = {'\0'};
    char unique2[100] = {'\0'};

    std::cout << "Input first word: ";
    std::cin.getline(input1, 100, '\n');

    std::cout << "Input second word: ";
    std::cin.getline(input2, 100, '\n');

    int resultCounter = 0;


    char currChar;
    bool isUnique;
    for (int i = 0; i < 99; ++i) {
        currChar = input1[i];
        if (currChar == '\0')
            break;
        isUnique = true;
        for (int j = 0; j < 100; ++j) {
            if (input1[j] == '\0')
                break;
            if (currChar == input1[j] && j != i) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            unique1[resultCounter++] = input1[i];
        }
    }

    resultCounter = 0;
    for (int i = 0; i < 99; ++i) {
        currChar = input2[i];
        if (currChar == '\0')
            break;
        isUnique = true;
        for (int j = 0; j < 100; ++j) {
            if (input2[j] == '\0')
                break;
            if (currChar == input2[j] && j != i) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            unique2[resultCounter++] = input2[i];
        }
    }


    std::cout << "\nUnique chars: ";
    for (int i = 0; i < 99; ++i) {
        if (unique1[i] == '\0') {
            std::cout << "\n\n";
            return;
        }

        currChar = unique1[i];

        for (int j = 0; j < 100; ++j) {
            if (unique2[j] == '\0') {
                break;
            }

            if (currChar == unique2[j]) {
                std::cout << currChar << ' ';
            }
        }
    }

    std::cout << "\n\n";
}

void outputCommonChars(char unique1[], char unique2[]) {
    char currChar;

    std::cout << "\nUnique chars: ";

    for (int i = 0; i < 99; ++i) {
        if (unique1[i] == '\0') {
            return;
        }

        currChar = unique1[i];

        for (int j = 0; j < 100; ++j) {
            if (unique2[i] == '\0') {
                break;
            }

            if (currChar == unique2[i]) {
                std::cout << currChar << '\t';
            }
        }
    }

    std::cout << std::endl;
}

char *findUniqueChars(char *input) {
    char result[100] = {'\0'};
    int resultCounter = 0;


    char currChar;
    bool isUnique;
    for (int i = 0; i < 99; ++i) {
        currChar = input[i];
        if (currChar == '\0')
            break;
        isUnique = true;
        for (int j = 0; j < 100; ++j) {
            if (input[j] == '\0')
                break;
            if (currChar == input[j] && j != i) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            result[resultCounter++] = input[i];
        }
    }

    return result;
}

