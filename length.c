#include <stdio.h>

int main() {
    char str[100], *p;
    int length = 0;

    printf("Enter a string: ");
    gets(str);

    p = str;
    while (*p != '\0') {
        length++;
        p++;
    }

    printf("Length = %d", length);
    return 0;
}
