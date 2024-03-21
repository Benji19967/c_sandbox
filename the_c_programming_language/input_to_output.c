#include <stdio.h>

main() {
    int c;

    // `!=` takes precedence over `=`, hence the extra parantheses
    while((c = getchar()) != EOF) {
        putchar(c);
    }
}
