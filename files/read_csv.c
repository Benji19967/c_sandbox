#include <stdio.h>   // contains type 'FILE'
#include <stdlib.h>  // contains 'atoi'
#include <string.h>

#define FILENAME "temperature.csv"
#define STRING_BUFFER_SIZE 200

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

/*
 * Parses lines in this format:
 *
 * 20240101,22,27
 *
 * from a CSV file
 */
int main() {
  char string_buffer[STRING_BUFFER_SIZE];
  const int num_lines_in_file = 7;

  // DailyTemperature dt[num_lines_in_file];
  DailyTemperature2 dt[num_lines_in_file];

  FILE *fptr = NULL;
  fptr = fopen(FILENAME, "r");

  // one call to fscanf reads one line
  if (fptr != NULL) {
    int i = 0;
    const int min_max_buffer_size = 2;
    while (fscanf(fptr, "%s", string_buffer) != EOF) {
      char *min_buffer = malloc(min_max_buffer_size);
      char *max_buffer = malloc(min_max_buffer_size);
      printf("%s\n", string_buffer);

      // DailyTemperature dt_local;
      // dt_local.day = malloc(8);

      DailyTemperature2 dt_local;  // No need to malloc

      const int date_string_size = 8;
      strncpy(dt_local.day, string_buffer, date_string_size);

      const int begin_min_temp_index = 9;
      const int begin_max_temp_index = 12;
      strncat(min_buffer, string_buffer + begin_max_temp_index,
              min_max_buffer_size);
      strncat(max_buffer, string_buffer + begin_max_temp_index,
              min_max_buffer_size);
      dt_local.min = atoi(min_buffer);
      dt_local.max = atoi(max_buffer);
      dt[i] = dt_local;
      i++;
      free(min_buffer);
      free(max_buffer);
    }
  }

  for (int i = 0; i < num_lines_in_file; i++) {
    printf("%s, %d, %d\n", dt[i].day, dt[i].min, dt[i].max);
  }
  fclose(fptr);
}
