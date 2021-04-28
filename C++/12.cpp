#include <iostream>
using namespace std;

int main() {
    string prompt = "Enter a random integer in the range 0 to 100 (inclusive)";
    int intArray[10];
    bool boolArray[101];

    for (int i = 0; i < 10; ++i) {
        cout << prompt;
        cin >> intArray[i];
    }

    for (int i = 0; i < 101; ++i) {
        boolArray[i] = false;
    }

    for (int i = 0; i < 10; ++i) {
        boolArray[intArray[i]] = true;
    }


    for (int i = 100; i >= 0; --i) {
        if (boolArray[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
