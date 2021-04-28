#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int maxSize = 0;
    string prompt = "Please enter a single word:";
    string str;
    vector<string> words;

    for (;;) {
        cout << prompt;
        cin >> str;

        if (str == "done") {
            break;
        }

        maxSize = (str.length()>maxSize)? str.length(): maxSize;
        words.push_back(str);
    }

    int x = ceil(sqrt(words.size()));
    for (int i = 0, z = 0; i < x; ++i) {
        for (int o = 0; o < x && z != words.size(); ++o,++z) {
            cout << left << setw(0) << words.at(z);
            for (int i = words.at(z).length(); i < maxSize+2; ++i) {
                cout << left << setw(0) << ".";
            }
        }
        cout << '\n';
    }
}
