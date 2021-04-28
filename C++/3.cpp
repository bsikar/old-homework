#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAXCOUNT 15
#define IS_EVEN(x) ((x % 2 == 0) ? 1 : 0)

void analyzeValues(int [], int, int *, int *, bool *, char *, double *);

int main() {
    int *ar = (int *)calloc(1, sizeof(int)), count, minVal, maxVal;
    bool isLastEven;
    char hexChar;
    double ave;

    std::string prompt = "Enter up to positive 15 numbers, separated by spaces, ending with a negative value to stop): ", errorMsg = "Error: No values were entered";
    std::cout << prompt << "\n";

    for (count = 0; count < MAXCOUNT; ++count) {
        int tmp = 0;
        std::cin >> tmp;
        if (tmp < 0) {
            if (count == 0) {
                std::cout << errorMsg << "\n";
            }
            break;
        }
        ar = (int *)realloc(ar, (count+1) * sizeof(int));
        ar[count] = tmp;
    }
    analyzeValues(ar, count, &minVal, &maxVal, &isLastEven, &hexChar, &ave);
    printf("Min value is %d\n"
     "Max value is %d\n"
     "The last value is %s\n"
     "The hex character for %d is %d\n"
     "The average value is %g\n",
     minVal, maxVal, (isLastEven)?"even":"odd", count, hexChar, ave);
    free(ar);
}

void analyzeValues(int nums[], int count, int *minVal, int *maxVal, bool *isLastEven, char *hexChar, double *ave) {
    int sum = nums[0];
    char tmp[2] = "";
    *maxVal = *minVal = nums[0];
    for (int i = 1; i < count; ++i) {
        if (*maxVal < nums[i]) {
            *maxVal = nums[i];
        }
            if (*minVal > nums[i]) {
        *minVal = nums[i];
        }
        sum += nums[i];
    }
    *isLastEven = IS_EVEN(nums[count-1]);
    sprintf(tmp, "%x", count);
    *hexChar = tmp[0];
    *ave = (float)sum / count;
}
