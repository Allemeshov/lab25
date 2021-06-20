#ifndef LAB_25_TASK2_H
#define LAB_25_TASK2_H

#include <iostream>
#include <utility>
#include <vector>

void task2();

void wrapRepeatedWords(std::string base, std::string search);

bool isSimilar(const char *base, const char *search, int startId);

void wrapBase(const char *search, char wrappedBase[300], int &i);

void outputWrappedBase(const char base[300], int count);


class Word {
private:
    std::string _word;
    bool _wrapped;

public:
    Word(std::string word);
    ~Word() = default;

    bool isWrapped();
    void wrap();
    std::string getText();
};


#endif //LAB_25_TASK2_H
