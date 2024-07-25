#include <stdio.h>  // contains type 'FILE'

int main() {
  char stringBuffer[200];

  FILE *fptr = NULL;
  fptr = fopen("temperature.csv", "r");

  // one call to fscanf reads one line
  if (fptr != NULL) {
    while (fscanf(fptr, "%s", stringBuffer) != EOF) {
      printf("%s\n", stringBuffer);
    }
  }

  fclose(fptr);
}
