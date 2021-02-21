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
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() 
{
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
