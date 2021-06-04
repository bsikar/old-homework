#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct Structure {
    int firstMember;
    int secondMember;
    int thirdMember;
    float forthMember;
};

int reverse(int);
float average(float, float);
void otherFunction(int);
char *englishEquivalent(long long);

int main(void) {
    struct Structure structure;

    printf("Enter the value for the first member\n");
    scanf("%d", &structure.firstMember);

    structure.secondMember = reverse(structure.firstMember);
    structure.thirdMember = structure.firstMember - structure.secondMember;
    structure.forthMember = average((float)structure.firstMember, (float)structure.secondMember);
    char *english = englishEquivalent((long long)structure.firstMember);

    //otherFunction(123);
    printf("firstMember: %d\n\
            secondMember: %d\n\
            thirdMember: %d\n\
            forthMember: %f\n%s\n",
            structure.firstMember,
            structure.secondMember,
            structure.thirdMember,
            structure.forthMember,
            english
    );

    free(english);

    return 0;
}

int reverse(int input) {
    int reversed = 0;

    for (int x = input; x != 0; x /= 10) {
        reversed = reversed * 10 + x % 10;
    }

    return reversed;
}

float average(float num1, float num2) {

    return (num1 + num2) / 2.;
}

void otherFunction(int input) {
    printf("%d\n", reverse(reverse(input)));
}

char *englishEquivalent(long long input) {
    char *singleDigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // 5
    char *teenDigits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"}; // 9
    char *tenDigits[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}; // 7
    char *output = calloc(4, sizeof(char));

    if (input < 0) {
       input *= -1;

        if (input < 10) {
            output = realloc(output, 15);
            sprintf(output, "negative %s", singleDigits[input]);

            return output;
        } else if (input < 20) {
            output = realloc(output, 19);
            sprintf(output, "negative %s", teenDigits[input - 10]);

            return output;
        } else if (input < 100) {
            output = realloc(output, 23);
            if (input % 10 != 0) {
                sprintf(output, "negative %s %s", tenDigits[input / 10], englishEquivalent(input % 10));
            } else {
                sprintf(output, "negative %s", tenDigits[input / 10]);
            }

            return output;
        } else if (input < 1000) {
            output = realloc(output, 37);
            if (input % 100 != 0) {
                sprintf(output, "negative %s hundred %s", englishEquivalent(input / 100), englishEquivalent(input % 100));
            } else {
                sprintf(output, "negative %s hundred", englishEquivalent(input / 100));
            }

            return output;
        } else if (input < 1000000) {
            output = realloc(output, 74);
            if (input % 1000 != 0) {
                sprintf(output, "negative %s thousand %s", englishEquivalent(input / 1000), englishEquivalent(input % 1000));
            } else {
                sprintf(output, "negative %s thousand", englishEquivalent(input / 1000));
            }

            return output;
        } else if (input < 1000000000) {
            output = realloc(output, 110);
            if (input % 1000000 != 0) {
                sprintf(output, "negative %s million %s", englishEquivalent(input / 1000000), englishEquivalent(input % 1000000));
            } else {
                sprintf(output, "negative %s million", englishEquivalent(input / 1000000));
            }

            return output;
        } else if (input < 1000000000000) {
            output = realloc(output, 146);
            if (input % 1000000000 != 0) {
                sprintf(output, "negative %s billion %s", englishEquivalent(input / 1000000000), englishEquivalent(input % 1000000000));
            } else {
                sprintf(output, "negative %s billion", englishEquivalent(input / 1000000000));
            }

            return output;
        }
    }

    if (input < 10) {
        output = realloc(output, 6);
        sprintf(output, "%s", singleDigits[input]);

        return output;
    } else if (input < 20) {
        output = realloc(output, 19);
        sprintf(output, "%s", teenDigits[input - 10]);

        return output;
    } else if (input < 100) {
        output = realloc(output, 14);
        if (input % 10 != 0) {
            sprintf(output, "%s %s", tenDigits[input / 10], englishEquivalent(input % 10));
        } else {
            sprintf(output, "%s", tenDigits[input / 10]);
        }

        return output;
    } else if (input < 1000) {
        output = realloc(output, 28);
        if (input % 100 != 0) {
            sprintf(output, "%s hundred %s", englishEquivalent(input / 100), englishEquivalent(input % 100));
        } else {
            sprintf(output, "%s hundred", englishEquivalent(input / 100));
        }

        return output;
    } else if (input < 1000000) {
        output = realloc(output, 65);
        if (input % 1000 != 0) {
            sprintf(output, "%s thousand %s", englishEquivalent(input / 1000), englishEquivalent(input % 1000));
        } else {
            sprintf(output, "%s thousand", englishEquivalent(input / 1000));
        }

        return output;
    } else if (input < 1000000000) {
        output = realloc(output, 101);
        if (input % 1000000 != 0) {
            sprintf(output, "%s million %s", englishEquivalent(input / 1000000), englishEquivalent(input % 1000000));
        } else {
            sprintf(output, "%s million", englishEquivalent(input / 1000000));
        }

        return output;
    } else if (input < 1000000000000) {
        output = realloc(output, 137);
        if (input % 1000000000 != 0) {
            sprintf(output, "%s billion %s", englishEquivalent(input / 1000000000), englishEquivalent(input % 1000000000));
        } else {
            sprintf(output, "%s billion", englishEquivalent(input / 1000000000));
        }

        return output;
    }

    free(output);
    return NULL;
}
