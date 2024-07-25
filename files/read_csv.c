#include <stdio.h>  // contains type 'FILE'

FILE *fptr;

int main() {
  fptr = fopen("sample.csv", "r");
  // TODO: read
  // https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
  fclose(fptr);
}
