#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

char *addStrings(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;

    char result[MAX_LEN + 1];
    int resultIdx = 0;

    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        result[resultIdx++] = (sum % 10) + '0';
    }
    result[resultIdx] = '\0';

    for (int i = 0, j = resultIdx - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    return strdup(result);
}

int main() {
    char num1[] = "1234567890123456789012345678901234567890";
    char num2[] = "9876543210987654321098765432109876543210";

    char *sum = addStrings(num1, num2);
    printf("Sum: %s\n", sum);

    // Remember to free the memory allocated by strdup
    free(sum);

    return 0;
}