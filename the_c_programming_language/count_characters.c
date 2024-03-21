#include <stdio.h>

main() {
    long num_chars;

    num_chars = 0;
    while(getchar() != EOF) {
        ++num_chars;
    }
    printf("%ld\n", num_chars);
}
