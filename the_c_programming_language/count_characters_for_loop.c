#include <stdio.h>

main() {
    double num_chars;

    for(num_chars = 0; getchar() != EOF; ++num_chars) {
        ; // this is a null statement. It is required as each loop requires a body.
    }

    // `%.0f` suppresses the decimal point and fraction part of the double from
    // being printed
    printf("%.0f\n", num_chars);
}
