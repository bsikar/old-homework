#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printMaze(char [][10]);
void initMaze(char [][10], int);

int main() {
    int innerWallGap;
    char maze[10][10];

    cout << "Enter a positive gap size for the inner wall between 0 and 4: ";
    cin >> innerWallGap;
    initMaze(maze, innerWallGap);
    printMaze(maze);
}


void printMaze(char m[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int o = 0; o < 10; ++o) {
            cout << m[i][o];
        }
        cout << "\n";
    }
}

void initMaze(char m[10][10], int gap) {
    for (int i = 0; i < 10; ++i) {
        for (int o = 0; o < 10; ++o) {
            if (i == 0 || i == 9) {
                m[i][o] = '*';
            } else if (o == 0 || o == 9) {
                m[i][o] = '*';
            } else {
                m[i][o] = ' ';
            }

            switch (gap) {
            case 0:
                for (int z = 0; z < 9; ++z) {
                    m[1][z] = m[8][z] = '*';
                }
                for (int z = 0; z < 6; ++z) {
                    m[2+z][1] = m[2+z][8] = '*';
                }
                break;
            case 1:
                for (int z = 0; z < 6; ++z) {
                    m[2][z+2] = m[7][z+2] = '*';
                }
                for (int z = 0; z < 4; ++z) {
                    m[3+z][2] = m[3+z][7] = '*';
                }
                break;
            case 2:
                for (int z = 0; z < 4; ++z) {
                    m[3][z+3] = m[6][z+3] = '*';
                }
                for (int z = 0; z < 2; ++z) {
                    m[4+z][3] = m[4+z][6] = '*';
                }
                break;
            case 3:
                for (int z = 0; z < 2; ++z) {
                    m[4][z+4] = m[5][z+4] = '*';
                }
                break;
            }
        }
    }
}
