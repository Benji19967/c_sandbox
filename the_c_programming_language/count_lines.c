#include <stdio.h>

main() {
    int c, line_count;

    line_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++line_count;
        }
    }

    printf("%d\n", line_count);
}
