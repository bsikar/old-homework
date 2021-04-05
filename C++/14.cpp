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
using namespace std;

string encrypt(string);
string decrypt(string);

int main() {
    string userInput;
    string userPrompt = "Enter a string to encrypt: ";
    string encryptedPrompt = "Your encrypted string is: ";
    string decryptedPrompt = "Your decrypted string is: ";

    cout << userPrompt;
    getline(cin, userInput);

    string encryptedString = encrypt(userInput);
    cout << encryptedPrompt << encryptedString << endl;

    string decryptedString = decrypt( encryptedString );
    cout << decryptedPrompt << decryptedString << endl;
}

string encrypt(string str) {
    for (int i = 0; i < (int)str.length(); ++i) {
        str.at(i) = str.at(i) + 3;
    }

    return str;
}

string decrypt(string str) {
    for (int i = 0; i < (int)str.length(); ++i) {
        str.at(i) = str.at(i) - 3;
    }

    return str;
}
