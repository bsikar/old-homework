#include <iostream>
#include <iostream>
#include <vector>
using std::cout;
using std::cin;

const int size = 5;

void swapMinToEnd(int [], int);

int main() {
    int anums[size] = {0};
    for (int i = 0; i < size; ++i) {
        cout << "Please enter an integer value: ";
        cin >> anums[i];
    }

    swapMinToEnd(anums, size);
    cout << "The smallest array value is " << anums[size-1] << '\n';
    cout << "Array values after swapMinToEnd() are:\n";
    for (int i = 0; i < size; ++i) {
        cout << anums[i] << ", " << '\n';
    }
}

void swapMinToEnd(int nums[], int size) {
    int tmp = nums[0];
    int index = 0;

    for (int i = 1; i < size; ++i) {
        if (tmp > nums[i]) {
            tmp = nums[i];
            index = i;
        }
    }

    for (int i = index; i < size - 1; ++i) {
        nums[i] = nums[i+1];
        nums[i+1] = tmp;
    }
}
