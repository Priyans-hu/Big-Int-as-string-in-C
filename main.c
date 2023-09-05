#include <stdio.h>
#include "addition.h"

int main() {
    char num1[] = "1234567890123456789012345678901234567890";
    char num2[] = "9876543210987654321098765432109876543210";

    char *sum = addStrings(num1, num2);
    printf("Sum: %s\n", sum);
    free(sum);

    return 0;
}