#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fillRandom(int *, int);
void printAll(int []);
int sumEvenNumbers(int *);

int main() {
    int seed;
    int v[11] = {0};

    cout << "Enter random seed integer: ";
    cin >> seed;
    srand(seed);

    fillRandom(v, 10);

    cout << "Random Values \n\n=";
    printAll(v);

    cout << "Sum of Even Numbers = ";
    cout << sumEvenNumbers(v) << endl;
}

void printAll(int v[]) {
    for (int i = 0; i < 10; ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void fillRandom(int v[], int n) {
    int number;
    for (int i = 0; i < n; ++i) {
        number = rand() % 10;
        v[i] = number;
    }
}

int sumEvenNumbers(int v[]) {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (!(v[i] % 2)) {
            sum += v[i];
        }
    }

    return sum;
}
