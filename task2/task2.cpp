#include "task2.h"


void FillWords(std::string &base, std::vector<Word> &words);

void outputWords(std::vector<Word> words);

void task2() {
    char trash[1];
    std::cin.getline(trash, 1, '\n');

    std::string inputBase;
    std::string inputSearch;

    std::cout << "Input base line: ";
    getline(std::cin, inputBase);

    std::cout << "Input searcher: ";
    getline(std::cin, inputSearch);


    wrapRepeatedWords(inputBase, inputSearch);

    std::cout << std::endl;
}

void wrapRepeatedWords(std::string base, std::string search) {
    std::vector<Word> words;

    FillWords(base, words);

    for (auto &word : words) {
        if (!word.isWrapped()) {
            for (auto &currWord : words) {
                if (currWord.getText() == search) {
                    if (!currWord.isWrapped())
                        currWord.wrap();
                }
            }
        }
    }


    outputWords(words);
}

void outputWords(std::vector<Word> words) {
    std::cout << "Wrapped words:\n";

    for (auto &word : words) {
        std::cout << word.getText() << ' ';
    }
    std::cout << std::endl;
}

void FillWords(std::string &base, std::vector<Word> &words) {
    std::string newWord;

    for (auto letter : base) {
        if (letter == ' ') {
            auto *wordDto = new Word(newWord);
            words.emplace_back(*wordDto);
            delete wordDto;
            newWord = "";
        } else {
            newWord += letter;
        }
    }
    auto *wordDto = new Word(newWord);
    words.emplace_back(*wordDto);
    delete wordDto;
}

Word::Word(std::string word) {
    this->_word = std::move(word);
    this->_wrapped = false;
}

bool Word::isWrapped() {
    return this->_wrapped;
}

void Word::wrap() {
    this->_word = "[" + this->_word + "]";
    this->_wrapped = true;
}

std::string Word::getText() {
    return this->_word;
}

