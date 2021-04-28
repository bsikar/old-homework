#include <iostream>
#include <string>

void sort3(int, int, int);

int main() {
    int a, b, c;
    std::cout << "Enter a value for A: ";
    std::cin >> a;
    std::cout << "Enter a value for B: ";
    std::cin >> b;
    std::cout << "Enter a value for C: ";
    std::cin >> c;

    sort3(a, b, c);
}

void sort3(int x, int y, int z) {
    if (x > y && x > z) {
        printf("%d, %d, %d\n", (y < z) ? y : z, (y > z) ? y : z, x );
    } else if (y > x && y > z) {
        printf("%d, %d, %d\n", (x < z) ? x : z, (x > z) ? x : z, y );
    } else if (z > x && z > y) {
        printf("%d, %d, %d\n", (y < x) ? y : x, (y > x) ? y : x, z );
    }
}
