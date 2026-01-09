#include <stdio.h>

int main() {
    char str[100], *p;
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    gets(str);

    p = str;

    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            if (*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u'||
                *p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U')
                vowels++;
            else
                consonants++;
        }
        p++;
    }

    printf("Vowels: %d\nConsonants: %d", vowels, consonants);
    return 0;
}
