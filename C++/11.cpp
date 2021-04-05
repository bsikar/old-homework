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

void sum(int &, string, string);
void sum(int &, int, int);
void sum(float &, float, float);
void testMyFunctions();

int main() {
    string stringAPrompt = "Enter a string for argument A: ";
    string stringBPrompt = "Enter a string for argument B: ";
    string intAPrompt = "Enter an integer for argument A: ";
    string intBPrompt = "Enter an integer for argument B: ";
    string floatAPrompt = "Enter a float for argument A: ";
    string floatBPrompt = "Enter a float for argument B: ";

    string stringA;
    string stringB;
    int stringSum = 0;

    int intA;
    int intB;
    int integerSum = 0;

    float floatA;
    float floatB;
    float floatSum = 0;

    cout << stringAPrompt;
    cin >> stringA;
    cout << stringBPrompt;
    cin >> stringB;

    cout << intAPrompt;
    cin >> intA;
    cout << intBPrompt;
    cin >> intB;

    cout << floatAPrompt;
    cin >> floatA;
    cout << floatBPrompt;
    cin >> floatB;

    sum(stringSum,stringA,stringB);
    sum(integerSum,intA,intB);
    sum(floatSum,floatA,floatB);
    testMyFunctions();

    cout << "The Sum of all three sums is: " << (stringSum + integerSum + floatSum) << endl;
}



void sum(int & result, string a, string b) {
    result = a.length()+b.length();
}

void sum(int & result, int a, int b) {
    result = a+b;
}

void sum(float & result, float a, float b) {
    result = a+b;
}

void testMyFunctions() {
    int stringTotal = -1;
    cout << "TESTING YOUR string sum() function...." << endl;
    sum(stringTotal, "1234", "");

    if (stringTotal != 4) {
        cout << "string sum()() returned '" << stringTotal << endl;
        cout << "ERROR - the result should have been 4.Please double-check your string sum() function." << endl;
        exit(1);
    }

    cout << "OK." << endl;

    cout << "TESTING YOUR integer sum() function...." << endl;
    int integerTotal = 0;

    sum(integerTotal, 10, 1);

    if (integerTotal != 11) {
        cout << "integer sum()() returned '" << integerTotal << endl;
        cout << "ERROR - the result should have been 11.Please double-check your integer sum() function." << endl;
        exit(1);
    }

    cout << "OK." << endl;

    cout << "TESTING YOUR float sum() function...." << endl;
    float a = 10.111111;
    float b = 12.999999;
    float floatTotal = 0;
    sum(floatTotal, a, b);

    if (floatTotal != a+b) {
        cout << "float sum()() returned '" << floatTotal << endl;
        cout << "ERROR - the result should have been " << (a+b) << ".Please double-check your float sum() function." << endl;
        exit(1);
    }

    cout << "OK." << endl;
}
