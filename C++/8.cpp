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
#include <string>

void sort3(int, int, int);

int main() {
    int a, b, c;
    std::cout << "Enter a value for A: ";
    std::cin >> a;
    std::cout << "Enter a value for B: ";
    std::cin >> b;
    std::cout << "Enter a value for C: ";
    std::cin >> c;
    
    sort3(a, b, c);
}

void sort3(int x, int y, int z) {
    if (x > y && x > z) {
        printf("%d, %d, %d\n", (y < z) ? y : z, (y > z) ? y : z, x );
    } else if (y > x && y > z) {
        printf("%d, %d, %d\n", (x < z) ? x : z, (x > z) ? x : z, y );
    } else if (z > x && z > y) {
        printf("%d, %d, %d\n", (y < x) ? y : x, (y > x) ? y : x, z );
    }
}
