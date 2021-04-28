#include <iostream>
using namespace std;

void binarySearch(int, int);

int main() {
    srand(time(NULL));
    cout << "Please think of a number between 1 and 100 (inclusive)" << endl;
    cout << ".... Now, please answer lower, higher, or yes, based on my questions." << endl;
    binarySearch(1, 100);
}

void binarySearch(int lowerBound, int upperBound) {
    if (lowerBound > upperBound) {
        cout << "You must have cheated!\n";

        return;
    }

    int guess = (rand() % (upperBound - lowerBound + 1)) + lowerBound;

    cout << "Is your number " << guess << "? ";
    string anw;
    cin >> anw;

    if (anw == "higher") {
        binarySearch(guess+1, upperBound);
    } else if (anw == "lower") {
        binarySearch(lowerBound, guess-1);
    } else {
        cout << "I win!\n";

        return;
    }
}
