#include <iostream>
#include "task1/task1.h"
#include "task2/task2.h"
#include "task3/task3.h"

bool ToQuit();

int main() {
    std::cout << "Лабораторная работа №24!" << std::endl;

    bool toQuit = false;
    int taskNumber = 0;
    std::string input = new char[2];

    while (!toQuit) {
        do {
            std::cout << "Номер задания: ";
            std::cin >> taskNumber;

            if (taskNumber == 1 || taskNumber == 2 || taskNumber == 3)
                break;
            else
                std::cout << "\tВыберите задание 1, 2 или 3!\n";

        } while (true);


        switch (taskNumber) {
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                task3();
                break;
            }
            default: {
                break;
            }
        }

        toQuit = ToQuit();
    }


    return 0;
}

bool ToQuit() {
    bool res;
    char input;
    do {
        std::cout << "Хотите закончить приложение? (y/n): ";
        input = static_cast<char>(getchar());

        if (input == 'y') {
            res = true;
            break;
        } else if (input == 'n') {
            res = false;
            break;
        } else
            std::cout << "\tInvalid input!\n";
    } while (true);

    return res;
}
