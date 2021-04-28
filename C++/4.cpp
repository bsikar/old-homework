#include <iostream>
#include <string>
using namespace std;

class Word {
    public:
        string text;
        Word *next = nullptr;

        Word(string _text) {
            text = _text;
        }
};

void printLinkedList(Word *);
void insertAtTail(Word *&, string);
string deleteWord(Word *&, string);

int main() {
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

void printLinkedList(Word *temp){
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
