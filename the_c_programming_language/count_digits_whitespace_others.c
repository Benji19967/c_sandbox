#include <stdio.h>

main() {
    int c, i, num_whitespace, num_others;
    int num_digit[10];

    num_whitespace = num_others = 0;
    for (i = 0; i < 10; ++i) {
        num_digit[i] = 0;
    }

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++num_digit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++num_whitespace;
        else 
            ++num_others;
    

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", num_digit[i]);
    printf(", num whitespace = %d", num_whitespace);
    printf(", num others = %d\n", num_others);
}
