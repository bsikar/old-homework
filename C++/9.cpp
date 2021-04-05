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
#include <vector>
using namespace std;

void testMyFunctions();
string getString(string);
string chooseTool();
string whoWinsTurn(string, string);
string getComputerTool();

int main() {
    testMyFunctions();
    srand(time(NULL));
    int playerPoints = 0, computerPoints = 0;

    while (playerPoints != 4 && computerPoints != 4) {
        string check = chooseTool();
        if (check == "quit") {
            cout << "Goodbye\n";
            break;
        }
        string tmp = whoWinsTurn(check, getComputerTool());

        if (tmp == "computer") {
            ++computerPoints;
        } else if (tmp == "player") {
            ++playerPoints;
        }
        cout << "The score is: Player Score = "<< playerPoints << ", Computer Score =" << computerPoints << "\n\n";
    }

    return 0;
}

void testMyFunctions() {
    string tmp;
    cout << "TESTING YOUR getString() function...." << endl;
    tmp = getString("Please type the word 'rock' (no quotes) and hit return: ");

    if (tmp !="rock") {
        cout << "getString() returned '" << tmp << "'" << endl;
        cout << "ERROR - that is not a match!Please double-check your getString() function." << endl;

        exit(1);
    }

    cout << "OK." << endl;
    cout << "TESTING YOUR chooseTool() function....";
    tmp = chooseTool();

    if (tmp != "rock" && tmp!= "paper" && tmp != "shears") {
        cout << "getTool() returned '" << tmp << "'" << endl;
        cout << "ERROR - that is not a rock, paper, or shears response!Please double-check your chooseTool() function." << endl;

        exit(1);
    }

    cout << "OK." << endl;
    cout << "TESTING YOUR whoWinsTurn() function....";
    vector<vector<string>> testSuite = {
        {"paper", "rock", "player"},
        {"rock", "paper", "computer"},

        {"rock", "shears", "player"},
        {"shears", "rock", "computer"},

        {"shears", "paper", "player"},
        {"paper", "shears", "computer"},

        {"paper", "paper", "tie"},
        {"rock", "rock", "tie"},
        {"shears", "shears", "tie"},
    };

    for (auto thisTest : testSuite) {
        if (whoWinsTurn(thisTest[0], thisTest[1]) != thisTest[2]) {
            cout << "whoWinsTurn() returned '" << whoWinsTurn(thisTest[0], thisTest[1]) << "'" <<" for player '" << thisTest[0] << "' vs computer '" << thisTest[1] << "'" << endl;
            cout << "ERROR - the answer should have been '" << thisTest[2] << "'. Please double-check your whoWinsTurn() function." << endl;

            exit(1);
        }
    }

    cout << "OK." << endl;
    cout << "TESTING COMPLETE - great job on your functions!" << endl;
    cout << "----------------------------------------------" << endl;
}

string getString(string myPrompt) {
    cout << myPrompt;
    string output;
    cin >> output;

    return output;
}

string chooseTool() {
    return getString("rock, paper, or shears? ");
}

string whoWinsTurn(string playerString, string computerString) {
    cout << "Player Entered: " << playerString << endl;
    cout << "Computer Entered: " << computerString << endl;

    if (playerString == computerString) {
        cout << "Tie\n";

        return "tie";
    }

    if (playerString == "rock") {
        if (computerString == "paper") {
            cout << "paper beats rock\n";

            return "computer";
        } else {
            cout << "rock beats shears\n";
        }
    }

    if (playerString == "paper") {
        if (computerString == "shears") {
            cout << "shears beats paper\n";

            return "computer";
        }
        else {
            cout << "paper beats rock\n";
        }
    }

    if (playerString == "shears") {
        if (computerString == "rock") {
            cout << "rock beats shears\n";

            return "computer";
        }
        else {
            cout << "shears beats paper\n";
        }
    }

    return "player";
}

string getComputerTool() {
    switch (rand() % 3) {
    case 0:
        return "rock";
    case 1:
        return "paper";
    case 2:
        return "shears";
    }

    return "ahhhahahahaha";
}
