# C 

## Why learn C?

- The language is small i.e. the number of features is relatively low.
- Many modern languages are based on it. They inherit some of C's features.
- It's closer to the machine. Using it will give one a deeper understanding of 
hardware. 
- The language is efficient. It is widely used in systems programming.

## Interview questions

https://dev.to/pauljlucas/c-interview-questions-4igp

## Confirm your compiler is working

### MacOS

`cc --version`

## `main()`

Every C program must contain a `main` function.
It is the entry point of every program. 

## pass-by-value

- C is pass-by-value without exception. 
- A function is not able to change the actual parameters value.

You can simulate pass-by-reference by passing a pointer to a value and then
changing the value the pointer is pointing to (not the value of the pointer itself, 
i.e. you could not make the pointer point to a different location within the function)
by dereferencing the pointer. 

## arrays vs pointers

- https://www.geeksforgeeks.org/difference-between-array-and-pointers/

- sizeof(arr): gives number of bytes of `arr`
- sizeof(ptr): always gives same size--size of pointer memory address

- When an array is passed as a parameter to a function it becomes a pointer
  - You cannot get the size of the object anymore!

## Formatting

- Use `clangd`
  - Can be installed with `Mason` in `Neovim`
  - Add a `.clang-format` file to root of project (or at `$HOME/.clang-format` for it 
  to be global) to specify a custom formatting style.

## Object files

Object files are the real output from compilation. 

- It's maching code
- Additional info
  - It tells the linker what symbols (names of global objects, functions, etc)
  are in it
  - It tells the linker what symbols it requires to work 

To generate object files use the `-c` flag: `gcc -c`

## Linker 

A linker takes all object files, along with other necessary libraries and modules,
and bundles them into one executable.

Most compilers just do this on their own (unless you tell them to just compile 
like: `gcc -c`)

## Errors

- There are no exceptions in C

### Errno

https://en.wikipedia.org/wiki/Errno.h

- Error codes can be found in `<errno.h>`
    - `errno` acts like an integer variable
    - When (some) functions detect an error, they store a value in `errno`
        - The function will typically return `NULL` or `-1` to indicate that an error 
        was detected (and hence, that `errno` was set to a non-zero value)
    - At program startup the value is `0`
