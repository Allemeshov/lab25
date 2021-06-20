#include "task3.h"

bool checkPal(char *s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void test1() {
    char s[256];
    gets(s);
    int i = 0, j, size = strlen(s);

    for (j = 0; j < size; j++) {
        if (s[j] == ' ') {
            if (s[i] == s[j - 1]) {
                if (checkPal(s, i, j - 1)) {
                    for (int g = 0; g < j - i + 1; g++)
                        for (int k = i; s[k] != '\0' || k < size - 1; k++)
                            s[k] = s[k + 1];
                    size -= j - i + 1;
                    j = i;
                } else {
                    i = j + 1;
                    j++;
                }

            } else {
                i = j + 1;
                j++;
            }
        }
    }
    if (checkPal(s, i, j - 1)) {
        for (int g = 0; g < j - i + 1; g++)
            for (int k = i; s[k] != '\0' || k < size - 1; k++)
                s[k] = s[k + 1];
        size -= j - i;
        j = i;
    }

    for (j = 0; j < size; j++) {
        printf("%c", s[j]);
    }


}

void test2() {
    char s[256];
    gets(s);
    printf("%s", regex_replace(s, regex{"[(]([^\)]+)[)]"}, "").c_str());

}

void task3() {
    char s[256];
    std::cmatch result;
    std::cmatch result2;
    std::regex reg("(\\-?)\\s*([0-9]+)\\s*(\\+|\\-|\\*|\\/)\\s*([0-9]+)");
    std::regex reg2("(\\-?)\\s*[0-9]+");
    std::ifstream file("text.txt");
    double ans;
    double x[2];

    double max = DBL_MIN, thisInd = -1, index = 0;
    if (file.is_open()) {
        while (!file.eof()) {
            thisInd++;
            file.getline(s, 256);
            if (std::regex_search(s, result, reg)) {
                if (regex_search(result[0].str().c_str(), result2, regex{"\\*"})) {
                    string r = result[0];
                    if (result2[0] == "*") {
                        sregex_iterator beg{r.cbegin(), r.cend(), reg2};
                        sregex_iterator end{};
                        int ind = 0;
                        for (auto i = beg; i != end; ++i) {
                            x[ind] = stoi(i->str());
                            ind++;
                        }
                        ans = (double) x[0] * x[1];
                    }
                } else if (regex_search(result[0].str().c_str(), result2, regex{"\\/"})) {
                    string r = result[0];
                    if (result2[0] == "/") {
                        sregex_iterator beg{r.cbegin(), r.cend(), reg2};
                        sregex_iterator end{};
                        int ind = 0;
                        for (auto i = beg; i != end; ++i) {
                            x[ind] = stoi(i->str());
                            ind++;
                        }
                        ans = (double) x[0] / x[1];
                    }
                } else if (regex_search(result[0].str().c_str(), result2, regex{"\\+"})) {
                    string r = result[0];
                    if (result2[0] == "+") {
                        sregex_iterator beg{r.cbegin(), r.cend(), reg2};
                        sregex_iterator end{};
                        int ind = 0;
                        for (auto i = beg; i != end; ++i) {
                            x[ind] = stoi(i->str());
                            ind++;
                        }
                        ans = (double) x[0] + x[1];
                    }
                } else if (regex_search(result[0].str().c_str(), result2, regex{"\\-"})) {
                    string r = result[0];
                    if (result2[0] == "-") {
                        sregex_iterator beg{r.cbegin(), r.cend(), reg2};
                        sregex_iterator end{};
                        int ind = 0;
                        for (auto i = beg; i != end; ++i) {
                            x[ind] = stoi(i->str());
                            ind++;
                        }
                        ans = (double) x[0] + x[1];
                    }
                }
            }
            if (ans > max) {
                max = ans;
                index = thisInd;
            }

        }
        file.close();
        file.open("text.txt");
        for (int i = 0; i <= index; i++)
            file.getline(s, 256);
        printf("%s", s);
    }

    cout << endl << max << endl;
}
