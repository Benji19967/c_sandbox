// How do C threads work?
// Why use a thread in C?
// How does a thread in C differ from other programming languages?

// pthread docs:
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html

#include <pthread.h>
#include <stdio.h>

// param is passed by reference
void *printnum(void *param) {
  int *number = (int *)param;

  printf("The value before edit is: %d\n", *number);
  *number = *number + 1;
  printf("The value after edit is: %d\n", *number);

  pthread_exit(param);
}

int main() {
  pthread_t thread_id;
  int value = 5;
  int *value_pointer = &value;

  printf("value: %d\n", value);
  printf("value_pointer (memory address): %d\n", value_pointer);
  printf("value at value_pointer: %d\n", *value_pointer);

  // (Reference to thread id, attributes, starting routine, arguments)
  // <pthread_t *, pthread_attr_t *, void *, void *)
  pthread_create(&thread_id, NULL, printnum, &value);

  int *new_value;
  // (thread id, reference to return value) <pthread_t, T>
  pthread_join(thread_id, (void **)&new_value);

  printf("The value after join is: %d\n", *new_value);
}
