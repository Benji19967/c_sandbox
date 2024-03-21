#include <stdio.h>

#define LOWER 0     // lower limit of table
#define UPPER 300   // upper limit
#define STEP  20    // step size 

main() {
    /* print Fahrenheit-Celsius table 
     * for fahr = 0, 20, ... 300 */

    float fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {

        // (5/9) would always yield 0 as integer division would be performed.
        //
        // (fahr-32) would yield the same result. If an integer is used with a 
        // floating point number in an operation, the interger gets converted to 
        // a floating point number. It's best to be explicit for the reader though.
        celsius = (5.0/9.0) * (fahr-32.0);

        // `%6.1f`: print a floating point number 6 chars wide and use 1 decimal place.
        printf("%3.0f\t%6.1f\n", fahr, celsius);

        fahr = fahr + STEP;
    }
}

