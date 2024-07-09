# C 

## Why learn C?

- The language is small i.e. the number of features is relatively low.
- Many modern languages are based on it. They inherit some of C's features.
- It's closer to the machine. Using it will give one a deeper understanding of 
hardware. 
- The language is efficient. It is widely used in systems programming.

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
