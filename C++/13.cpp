/* MIT License
 *
 * Copyright (c) 2021 Brighton Sikarskie
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
