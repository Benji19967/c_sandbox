#include <stdio.h>

#define IN  1  // inside a word
#define OUT 0  // outside a word


main() {
    int c, state, num_lines, num_words, num_chars;

    state = OUT;
    num_lines = num_words = num_chars = 0;
    while ((c = getchar()) != EOF) {
        ++num_chars;
        if (c == '\n')
            ++num_lines;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++num_words;
        }
    }

    printf("%d %d %d\n", num_lines, num_words, num_chars);
}
