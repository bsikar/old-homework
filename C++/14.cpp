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
