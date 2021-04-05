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
