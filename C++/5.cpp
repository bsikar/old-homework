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
