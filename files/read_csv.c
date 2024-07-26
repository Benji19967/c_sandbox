#include <stdio.h>   // contains type 'FILE'
#include <stdlib.h>  // contains 'atoi'
#include <string.h>

typedef struct DailyTemperature {
  char *day;
  int min;
  int max;
} DailyTemperature;

typedef struct DailyTemperature2 {
  char day[8];
  int min;
  int max;
} DailyTemperature2;

int main() {
  char stringBuffer[200];
  // DailyTemperature dt[7];
  DailyTemperature2 dt[7];

  FILE *fptr = NULL;
  fptr = fopen("temperature.csv", "r");

  // one call to fscanf reads one line
  if (fptr != NULL) {
    int i = 0;
    while (fscanf(fptr, "%s", stringBuffer) != EOF) {
      char *minBuffer = malloc(2);
      char *maxBuffer = malloc(2);
      printf("%s\n", stringBuffer);

      // DailyTemperature dt_local;
      // dt_local.day = malloc(8);

      DailyTemperature2 dt_local;  // No need to malloc

      strncpy(dt_local.day, stringBuffer, 8);

      strncat(minBuffer, stringBuffer + 9, 2);
      strncat(maxBuffer, stringBuffer + 12, 2);
      dt_local.min = atoi(minBuffer);
      dt_local.max = atoi(maxBuffer);
      dt[i] = dt_local;
      i++;
      free(minBuffer);
      free(maxBuffer);
    }
  }
  for (int i = 0; i < 7; i++) {
    printf("%s, %d, %d\n", dt[i].day, dt[i].min, dt[i].max);
  }
  fclose(fptr);
}
