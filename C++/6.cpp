#include <iostream>
#include <iomanip>
using namespace std;

class Hole {
    public:
        bool isEmpty = true;
        int id = -1;

        Hole *upRight = nullptr;
        Hole *upLeft = nullptr;
        Hole *downLeft = nullptr;
        Hole *downRight = nullptr;
        Hole *left = nullptr;
        Hole *right = nullptr;

        Hole(bool e, int num) {
            isEmpty = e;
            id = num;
        }

        void printHoleID() {
            cout << setw(4) << id;
        }

        void printHolePeg() {
            if (isEmpty) {
                cout << setw(4) << "-";
            } else {
                cout << setw(4) << "p";
            }
        }
};

class PegJumpGame {
    private:
        Hole *holes[15] = {
            nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
        };

    public:
        PegJumpGame() {
            holes[0] = new Hole(true, 0);
            holes[1] = new Hole(false, 1);
            holes[2] = new Hole(false, 2);
            holes[3] = new Hole(false, 3);
            holes[4] = new Hole(false, 4);
            holes[5] = new Hole(false, 5);
            holes[6] = new Hole(false, 6);
            holes[7] = new Hole(false, 7);
            holes[8] = new Hole(false, 8);
            holes[9] = new Hole(false, 9);
            holes[10] = new Hole(false, 10);
            holes[11] = new Hole(false, 11);
            holes[12] = new Hole(false, 12);
            holes[13] = new Hole(false, 13);
            holes[14] = new Hole(false, 14);

            holes[0]->downLeft = holes[1];
            holes[0]->downRight = holes[2];

            holes[1]->upRight = holes[0];
            holes[1]->right = holes[2];
            holes[1]->downLeft = holes[3];
            holes[1]->downRight = holes[4];

            holes[2]->upLeft = holes[0];
            holes[2]->left = holes[1];
            holes[2]->downLeft = holes[4];
            holes[2]->downRight = holes[5];

            holes[3]->upRight = holes[1];
            holes[3]->right = holes[4];
            holes[3]->downLeft = holes[6];
            holes[3]->downRight = holes[7];

            holes[4]->upLeft = holes[1];
            holes[4]->upRight = holes[2];
            holes[4]->left = holes[3];
            holes[4]->right = holes[5];
            holes[4]->downLeft = holes[7];
            holes[4]->downRight = holes[8];

            holes[5]->upLeft = holes[2];
            holes[5]->left = holes[4];
            holes[5]->downLeft = holes[8];
            holes[5]->downRight = holes[9];

            holes[6]->upRight = holes[3];
            holes[6]->right = holes[7];
            holes[6]->downLeft = holes[10];
            holes[6]->downRight = holes[11];

            holes[7]->upLeft = holes[3];
            holes[7]->upRight = holes[4];
            holes[7]->left = holes[6];
            holes[7]->right = holes[8];
            holes[7]->downLeft = holes[11];
            holes[7]->downRight = holes[12];

            holes[8]->upLeft = holes[4];
            holes[8]->upRight = holes[5];
            holes[8]->left = holes[7];
            holes[8]->right = holes[9];
            holes[8]->downLeft = holes[12];
            holes[8]->downRight = holes[13];

            holes[9]->upLeft = holes[5];
            holes[9]->left = holes[8];
            holes[9]->downLeft = holes[13];
            holes[9]->downRight = holes[14];

            holes[10]->upRight = holes[6];
            holes[10]->right = holes[11];

            holes[11]->upLeft = holes[6];
            holes[11]->upRight = holes[7];
            holes[11]->left = holes[10];
            holes[11]->right = holes[12];

            holes[12]->upLeft = holes[7];
            holes[12]->upRight = holes[8];
            holes[12]->left = holes[11];
            holes[12]->right = holes[13];

            holes[13]->upLeft = holes[8];
            holes[13]->upRight = holes[9];
            holes[13]->left = holes[12];
            holes[13]->right = holes[14];

            holes[14]->upLeft = holes[9];
            holes[14]->left = holes[13];
        }

        bool movePeg(int fromID, string direction) {
            Hole *holePtr = holes[fromID];
            if (holePtr->isEmpty) {
                cout << "\nSorry There is no peg I can use to jump at location " << fromID << ". Move aborted.\n\n";
                return false;
            }

            Hole *jumpOverHole = nullptr;
            Hole *jumpToHole = nullptr;

            if (direction == "left") {
                jumpOverHole = holePtr->left;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->left;
                }
            } else if (direction == "right") {
                jumpOverHole = holePtr->right;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->right;
                }
            } else if (direction == "upRight" || direction == "upright") {
                jumpOverHole = holePtr->upRight;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->upRight;
                }
            } else if (direction == "upLeft" || direction == "upleft") {
                jumpOverHole = holePtr->upLeft;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->upLeft;
                }
            } else if (direction == "downLeft" || direction == "downleft") {
                jumpOverHole = holePtr->downLeft;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->downLeft;
                }
            } else if (direction == "downRight" || direction == "downright") {
                jumpOverHole = holePtr->downRight;
                if (jumpOverHole != nullptr) {
                    jumpToHole = jumpOverHole->downRight;
                }
            } else {
                cout << "\nSorry I do not recognize the direction " << direction << ". Move aborted.\n" << endl;
                return false;
            }

            return doJump(holePtr, jumpOverHole, jumpToHole);
        }

        bool doJump(Hole *jumpFromHolePtr, Hole *jumpOverHolePtr, Hole *jumpToHolePtr) {
            if (jumpFromHolePtr == nullptr || jumpToHolePtr == nullptr || jumpOverHolePtr == nullptr) {
                return false;
            }

            if (jumpToHolePtr->isEmpty == false) {
                return false;
            }

            jumpToHolePtr->isEmpty = false;
            jumpFromHolePtr->isEmpty = true;
            jumpOverHolePtr->isEmpty = true;

            return true;
        }

        bool printBoard() {
            for (int loop = 0; loop < 2; ++loop) {
                int holeCount = 0, holeIDProblems = 0, linkProblems = 0;
                string pad(14, ' ');
                Hole *holePtr = holes[0];
                if (holePtr == nullptr) {
                    cout << "printBoard(): ERROR: holes[0] is null. Cannot print empty board.Abort" << endl;
                    return false;
                }

                if (loop == 0) {
                    cout << "Board Hole Position IDs are:" << endl;
                } else {
                    cout << "\nYour Pegs are:" << endl;
                }

                cout << pad;

                while (holePtr != nullptr) {
                    if (loop == 0) {
                        holePtr->printHoleID();
                    } else {
                        holePtr->printHolePeg();
                    }

                    if (holeCount++ != holePtr->id) {
                        holeIDProblems++;
                    }

                    if (loop == 0) {
                        linkProblems += (holePtr->left != nullptr ? (holePtr->left->right != holePtr ? 1 : 0) : 0 );
                        linkProblems += (holePtr->right != nullptr ? (holePtr->right->left != holePtr ? 1 : 0) : 0 );
                        linkProblems += (holePtr->upRight != nullptr ? (holePtr->upRight->downLeft != holePtr ? 1 : 0) : 0 );
                        linkProblems += (holePtr->upLeft != nullptr ? (holePtr->upLeft->downRight != holePtr ? 1 : 0) : 0 );
                        linkProblems += (holePtr->downLeft != nullptr ? (holePtr->downLeft->upRight != holePtr ? 1 : 0) : 0 );
                        linkProblems += (holePtr->downRight != nullptr ? (holePtr->downRight->upLeft != holePtr ? 1 : 0) : 0 );
                        if (linkProblems > 0) {
                            cout << "\nPrintBoard(): Error: encountered " << linkProblems << " problems with the links on hole with ID == " << holePtr->id << ".Please check your constructor. Abort." << endl;
                            return false;
                        }

                        if (holePtr->left == nullptr && (holePtr->id != 0 && holePtr->id != 1 && holePtr->id !=3 && holePtr->id !=6 && holePtr->id !=10)) {
                            cout << "\nPrintBoard(): Error: left pointer for Hole with id " << holePtr->id << " should NOT be null. Please check your constructor. Abort." << endl;
                            return false;
                        }

                        if (holePtr->right == nullptr && (holePtr->id != 0 && holePtr->id != 2 && holePtr->id !=5 && holePtr->id !=9 && holePtr->id !=14)) {
                            cout << "\nPrintBoard(): Error: right pointer for Hole with id " << holePtr->id << " should NOT be null. Please check your constructor. Abort." << endl;
                            return false;
                        }

                        if (holePtr->downLeft == nullptr && (holePtr->id != 10 && holePtr->id != 11 && holePtr->id !=12 && holePtr->id !=13 && holePtr->id !=14)) {
                            cout << "\nPrintBoard(): Error: downLeft pointer for Hole with id " << holePtr->id << " should NOT be null. Please check your constructor. Abort." << endl;
                            return false;
                        }

                        if (holePtr->downRight == nullptr && (holePtr->id != 10 && holePtr->id != 11 && holePtr->id !=12 && holePtr->id !=13 && holePtr->id !=14)) {
                            cout << "\nPrintBoard(): Error: downRight pointer for Hole with id " << holePtr->id << " should NOT be null. Please check your constructor. Abort." << endl;
                            return false;
                        }
                    }

                    if (holePtr->right != nullptr) {
                        holePtr = holePtr->right;
                    } else {
                        while (holePtr->left != nullptr) {
                            holePtr = holePtr->left;
                        }

                        if (holePtr->downLeft != nullptr) {
                            holePtr = holePtr->downLeft;
                            pad.pop_back();
                            pad.pop_back();
                            cout << endl;
                            cout << pad;
                        } else {
                            break;
                        }
                    }
                }
                cout << endl;
                if (loop == 0 && holeIDProblems != 0) {
                    cout << "\nPrintBoard(): Error: " << holeIDProblems << " of your hole IDs shown above are not correct! Please check your constructor. Abort." << endl;
                    return false;
                }
            }

            return true;
        }
};

int main() {
    cout << "Calling PegJumpGame constructor...." << endl;
    PegJumpGame p;
    cout << "OK Let's play!!" << endl;

    int pegToMove;
    string direction;
    bool moveSucceeded = false;

    if (!p.printBoard()) {
        cout << "printBoard found a problem... abort program." << endl;
        return 1;
    }

    for (;;) {
        cout << "\nWhat Hole ID would you like to move a peg from (0..14)? ";
        cin >> pegToMove;

        if (pegToMove <0 || pegToMove > 14) {
            cout << "Sorry - that is not a valid number... please try again! " << endl;
            continue;
        }

        cout << "In what direction would you like to move peg #" << pegToMove << " (upLeft, upRight, left, right, downLeft, or downRight) ? ";
        cin >> direction;

        moveSucceeded = p.movePeg(pegToMove, direction);

        if (moveSucceeded) {
            cout << "Well-played!" << endl;
            if (!p.printBoard()) {
                break;
            }
        } else {
            cout << "Sorry that move did not work" << endl;
        }
    }
}

