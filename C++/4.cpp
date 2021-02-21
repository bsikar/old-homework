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

class Word
{
    public:
        string text;
        Word *next = nullptr;

        Word(string _text)
        {
            text = _text;
        }
};

void printLinkedList(Word *);
void insertAtTail(Word *&, string);
string deleteWord(Word *&, string);

int main()
{
    Word *head = nullptr;
    printLinkedList(head);

    for (;;) {
        cout << "What word would you like to insert? ";
        string str; 
        cin >> str; 
        insertAtTail(head, str);
        printLinkedList(head);
        cout << endl;
    }
}

void printLinkedList(Word *temp)  {
    if (temp == nullptr) {
        cout << "(empty)" <<endl;

        return;
    }

    while (temp != nullptr) {
        cout << temp->text << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Word *&head, string newString) {
    if (head == nullptr) {
        head = new Word(newString);

        return;
    }

    Word *temp = nullptr;
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Word(newString);
}
