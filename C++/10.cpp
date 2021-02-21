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
#include <vector>
#include <string>
using namespace std;

void fillRandom(int *, int); 
void printAll(int []); 
int sumEvenNumbers(int *); 

int main() 
{
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

void printAll(int v[])
{
    for (int i = 0; i < 10; ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void fillRandom(int v[], int n) 
{
    int number;
    for (int i = 0; i < n; ++i) {
        number = rand() % 10;
        v[i] = number;
    }
}

int sumEvenNumbers(int v[])
{
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (!(v[i] % 2)) {
            sum += v[i];
        }
    }

    return sum;
}
