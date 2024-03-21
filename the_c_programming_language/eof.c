#include <stdio.h>

main() {
    // Will print -1
    printf("%d\n", EOF); 

    // Will print nothing as there is not character that corresponds to the integer -1
    putchar(EOF); 
}
