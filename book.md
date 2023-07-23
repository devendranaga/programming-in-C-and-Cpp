# Programming in C and C++

## Introduction

This book tries to explain programming in C and C++. C and C++ although are the oldest programming languages they are still in use by most of the operating systems such as Linux, RTOSes such as FreeRTOS.

Both languages are still used in firmware development. Sometimes with libc and libstdc++ and sometimes no use
of libc and libstdc++. When writing code for Linux systems, most of the time library linkage can be used to write software. Using the library simplifies the software development as it provides most of the interfaces.

For example, the following are provided.

1. string manipulation
2. console operations (writing to and reading from console).
3. file system interaction (FILE i/o)
4. Operating system abstractions in case of C++ (such as creation and use of threads, interacting with file system)

The compiler implements the C, C++ languages. To install `gcc` and `g++` on Ubuntu:

```bash
sudo apt install gcc g++
```

### Audience

# C programming

## Basic Hello World program

Below is a basic hello world program in C.

```c
#include <stdio.h>

int main()
{
    printf("Hello World\n);

    return 0;
}
```
<i>Example.1 : hello_world.c</i>


The `main()` is a function and the program always executes from `main()`.
The function call `printf`, allows the program to write to a console.
The header file `stdio.h` contains the prototype of `printf`.

The statement `return 0` specifies that the function returns 0. In C, a function may or may not return depend on the function signature.

In order to run the program above, we need to create an executable. To create this executable, we need to compile it.

Copy and Paste the above program in a text editor and save it in a file called `hello_world.c`.

All the source code files written in C will have an extension `.c` or `.h`.

The files with `.h` extensionn are called header files. Header files contain the following.

1. Macro definitions.
2. Function prototypes.
3. Data structure definitions.

The below command is used to compile the C file.

```bash
gcc hello_world.c
```

## Basic Data types

Below are the following data types in C. All are applicable for C++ as well.

Below are some of the data types for 32 bit systems.

| S.No | type | description | ranges |
|------|------|-------------|--------|
| 1 | `char` | 1 byte signed integer | -127 to 127 |
| 2 | `unsigned char` | 1 byte unsigned integer | 0 to 128 |
| 3 | `short int` | 2 byte signed integer | -32767 to 32767 |
| 4 | `unsigned short int` | 2 byte unsigned integer | 0 to 65535 |
| 5 | `int` | 4 byte signed integer | -2147483648 to 2147483647 |
| 6 | `unsigned int` | 4 byte unsigned integer | 0 to 4294967295 |
| 7 | `float` | 4 byte floating point variable | - |
| 8 | `double` | 4 / 8 byte double variable | - |

A variable of the above type can be declared as follows.

```c
int a;
```

a is a variable of type `int`.

```c
int a = 4;
```

The above statement initializes a to 4.

```c
int a;

a = 4;
```

The above statement assigns a to 4.

Sometimes in a program we initialize variables and we assign the variables a value sometime later.

A variable that is not initialized is called uninitialized variable. Uninitialized variables are a bigger problem when using them. The reason being that they hold some unknown value when declared.

Each declared variable is associated with a type. Read Recap section about the variables and their scope.

### sizeof operator

The `sizeof` operator is used find out the size of a data type. Below is an example.

```c
#include <stdio.h>

int main()
{
    int a;

    printf("size a: %d\n", sizeof(a));

    return 0;
}
```

The `%d` used to print integers. The function `printf` recognizes the integer variables given as function arguments when specified as `%d`.

The body portion start with `"` and end with `"` is called as string. More about the strings in the Strings section below.

Below are some of the format specifiers.

| S.No | Format specifier | Meaning |
|------|------------------|---------|
| 1 | `%d` | integer |
| 2 | `%c` | character |
| 3 | `%s` | string |
| 4 | `%f` | float or double |
| 5 | `%u` | unsigned integer |
| 6 | `%ld` | long integer |
| 7 | `%lld` | longlong integer |
| 8 | `%lu` | long unsigned integer |
| 9 | `%llu` | long long unsigned integer |
| 10 | `%x` | hexadecimal |

Below are some more functions that use the format specifiers.

1. scanf
2. fprintf
3. fscanf
4. vfprintf
5. vfscanf



### type definition

Any type can be type defined to another type. The keyword `typedef` is used for this purpose.

```c
typedef int integer_t;
```

Now, `integer_t` can be used as a new type to declare variables. The `typedef` can be applied for many other data types such as structures and function pointers.

### operators

C has below operators that can be used on the variables of given types.

| S.No | operator | meaning |
|------|----------|---------|
| 1 | `+` | addition |
| 2 | `-` | subtraction |
| 3 | `*` | multiplication |
| 4 | `/` | division |
| 5 | `%` | modulo |
| 6 | `=` | equals to |
| 7 | `==` | comparison operator |
| 8 | `||` | logical OR |
| 9 | `&&` | logical AND |
| 10 | `|` | OR |
| 11 | `&` | AND |
| 12 | `^` | XOR |
| 13 | `!` | NOT |
| 14 | `!!` | Logical NOT |

Below example shows an example of the operators.

```c
#include <stdio.h>

int main()
{
    int a = 4;
    int b = 2;
    int sum;
    int sub;
    int mul;
    int div;
    int mod;
    
    sum = a + b; // add two numbers
    sub = a - b; // subtract two numbers
    mul = a * b; // multiply two numbers
    div = a / b; // divide two numbers
    mod = a % b; // modulo two numbers
    
    printf("sum %d sub %d\n", sum, sub);
    printf("mul %d div %d modulo %d\n", mul, div, mod);
    
    return 0;
}
```

## Control statements

**1. if else statement**

The `if` statement provides a method of controlling the execution path of a program based on the data.

The `if` statement holds the condition and is evaluated for true or false. If the condition is true, then the statements in the `if` are executed, Otherwise the statements in `else` are executed.

The `else` statement in general is followed by the `if` statement and never alone. The `else` statement does not contain any condition test like the `if`.

```c
#include <stdio.h>

int main()
{
    char p = 'd';

    if (p == 'd') {
        printf("p '%c' is %c\n", p);
    } else {
        printf("p '%c' is not 'd'\n", p);
    }

    return 0;
}
```

Generally the `else` statement does not have to follow the `if` statement. But it is a good practise to have an `else` statement if needed.

**2. if else-if statement**

The `if else-if` statement also called `if else ladder` that is used to construct a series of `if else if` conditions.

Below is an example of the `if else-if` ladder.

```c
#include <stdio.h>

int main()
{
    int number = 50;
    
    if (number < 50) {
        printf("number is less than 50\n");
    } else if (number > 50) {
        printf("number is greater than 50\n");
    } else if (number == 50) {
        printf("number is equal to 50\n");
    } else {
        printf("number is [%d] unknown\n", number);
    }
    
    return 0;
}
```

In general `if else-if` ladders are not used in many large scale applications unless there are ranges involved. That is why the
above example shows the use of `if else-if` with the ranges.

For any direct comparision (`==`) the `switch` statement is used.

**3. Switch statement**

The switch statement example is as shown below.

```c
#include <stdio.h>

int main()
{
    int n = 50;
    
    switch (n) {
        case 10:
        	printf("number is 10\n");
        break;
        case 20:
        	printf("number is 20\n");
        break;
        case 50:
        	printf("number is 50\n");
        break;
        default:
        	printf("number [%d] is unknown\n", n);
        break;
    }
    return 0;
}
```

**4. Trigraph ?: sequence**

## Loops

**1. While loop**

**2. For loop**

**3. Goto statement**

## Strings

## Arrays

**1. One Dimensional Arrays**

One dimensional array are the base type in arrays.

An array of integers is defined as,

```c
int a[10];
```

Above statement defines an array `a` of 10 integers. Each element in the array is an element of type integer.

Array indexes start from 0. Each item in the array is indexed with regular numbers ranging from 0 to 9.

Maximum elements in the above array are 10 but the last index of the 10th element is 9, not 10. Accessing the array beyond its maximum range is also called out of bounds access. Out of bounds accesses are major security problem as the element is accessing an address beyond the allocated range.

Below program assigns the elements in the array.

```c
#include <stdio.h>

int main()
{
    int a[10];
    int i = 0;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        a[i] = i;
    }

    printf("array elements:\n");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("\ta[%d] = %d\n", i, a[i]);
    }
    printf("\n");
}
```

**2. Two Dimensional Arrays**

**3. Three Dimensional Arrays**

## Strings

The below statement is a base char type.

```c
char d;
```

String is an array of characters ending with `\0`. For example, the below statement defines a base string type.

```c
char d[20];
```

declares a string of 19 elements with the last element allocated to the `\0`.

### String manipulation operations

The header file `string.h` contains the functions that help to manipulate the string data.

## Dynamic Memory Allocation

**1. malloc**

**2. calloc**

**3. realloc**

**4. free**

## Library Functions

**1. atoi**

**2. strtol**

**3. strtod**

**4. strtoul**

## Functions

## Pointers

### Recap about variables and scope

**Local variables**

**Global variables**

**1. static type**

**2. auto type**

The type `auto` does not signify anything in C. This type is very significant however in C++.

**3. volatile type**

### Function Pointers

## Structures

### Bit fields

### Structure packing

### Structure pointer

## Enumeration

## Unions

## Appendix

The `stdint.h` from libc has further more data types. See `/usr/include/stdint.h`
The `limits.h` from libc contains all the ranges of the base types. See `/usr/include/limits.h`.

### Command line arguments (argc, argv)

### File I/O

#### Basic operations

**1. Opening and Closing a file**

**2. Reading from a File**

**3. Writing to a file**

#### Operating with the binary files

### I/O operations



# C++ programming

## New operators in C++

**1. The Reference (`&`) operator.**

## Classes

Classes in C++ are similar to the structures in C. The Class is enclosure for data and operations on the data.

## Polymorphism

## Inheritance

### Simple Inheritance

### Multiple inheritance

### Abstract Classes

## Appendix

### Scoppe and Lifetime

#### shared_ptr, unique_ptr

### Threads

### File systems

## Design Patterns

### Factory design pattern

### Singleton pattern


# Data Structures

## Linked Lists

## Doubly Linked Lists

## Circular Linked Lists

## Stack

## Queue

## Ring Buffer

## Tree
