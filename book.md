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
    // prints Hello World on console
    printf("Hello World\n);

    return 0;
}
```
<i>Example.1 : hello_world.c</i>


The `main()` is a function and the program always executes from `main()`.
The function call `printf`, allows the program to write to a console.
The header file `stdio.h` contains the prototype of `printf`.

The `//` indicates comment line. Anything that goes after `//` for the entire line is ignored.

There is another type of comment style that start with `/*` and ends with `*/`. This can be used as a multiline comment.

Here's one example,

```c
/*
 This is a multi line comment,
 showing more than one line can be written.
 */
```

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

```c
int a = 0x20;
```

initializes `a` with a hexadecimal number. Hexadecimals are noted with the `0x`.

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

The `sizeof` operator can be used on a variable or the data type itself. Such as calling `sizeof(int)` is valid.

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

Below are some more functions that use the format specifiers. Functions are described in detail below.

| S.No | Function Name | 
|------|---------------|
| 1 | `scanf` |
| 2 | `fprintf` |
| 3 | `fscanf` |
| 4 | `vfprintf` |
| 5 | `vfscanf` |



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

The `!!` statement is used to check the value of a number is non zero or zero. Below example shows how to use it.

```c
#include <stdio.h>

int main()
{
    int a = 4;
    int b = 0;

    printf("a=%d b=%d\n", !!a, !!b);

    return 0;
}
```

Below example shows the use of `&` `|` and `^` operators.

```c
#include <stdio.h>

int main()
{
    int a = 0x80;
    int b = 0x81;

    printf("AND 0x%02x OR 0x%02x XOR 0x%02x\n",
                a & b, a | b, a ^ b);

    return 0;
}
```

The output is :

```c
AND 0x80 OR 0x81 XOR 0x01
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

For example, the `&&` and `||` can be used within the `if` conditional.

Below is an example,

```c
#include <stdio.h>

int main()
{
    int a = 0x80;
    int b = 0x0;

    if (a && b) {
        printf("a and b are non zero\n");
    } else if (a || b) {
        printf("a or b are non zero\n");
    }

    return 0;
}
```

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

As you can see, the switch has a series of `case` statements and a `default` statement. Each of the `case` statement ends with a `break` statement if necessary. If there is no `break` statement then the statements fall through. Below example shows the descripton.

```c
#include <stdio.h>

int main()
{
    int n = 10;

    switch (n) {
        case 10:
        case 20:
            printf("n is %d\n", n);
        break;
    }

    return 0;
}
```

The output is :

```bash
n is 10
```

In some cases the fallthroughs are needed to have execute a series of statements for more than one case types.

**4. Trigraph ?: sequence**

The `?:` is called a trigraph sequence. Here's how it can be used.

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 5;
    int res;

    res = (a > b) ? a : b;

    printf("res %d\n", res);

    return 0;
}

```

Trigraphs are similar to the if else cases the true case is right after the `?` and the false case is right after the `:`.

They are mostly useful when writing simple test on a variable instead of the general `if else` conditionals. 

## Loops

**1. While loop**

The `while` loop allows to loop over a certain condition until it fails. An example of the `while` is as follows.

```c
while (condition) {
    // statements
}
```

An example use of `while` loop is as follows.

```c
#include <stdio.h>

int main()
{
    int i = 0;

    while (i < 10) {
        printf("i %d\n", i);
        i ++;
    }

    return 0;
}
```

In the above program the loop repeats until `i` reaches 10. Upon reaching 10, the while condition fails breaking the loop.

The `break` statement can be used in the `while` loop as well.

```c
int main()
{
    int i = 0;

    while (1) {
        if (i >= 10) {
            break;
        }
        printf("%d\n", i);
        i ++;
    }

    return 0;
}
```

Above program shows the use of `while (1)`. Generally this means that the condition in the `while` loop is never false. It is an infinite loop.

Generally infinite loops are not preferable in programming without any conditional checks in the `while` statement.

The infinite loops generally do nothing but increase in CPU load on the process the program runs and consumes the CPU cycles unnecessarily. However, some programs written for the
operating systems do need to run infinitely (such as graphics, display, editors etc). To do this, operating systems employ certain event based mechanisms supported by the
hardware. This ensures that the program executes only based on certain events.

**2. For loop**

The `for` loop is similar to the `while` loop. The syntax is as follows,

```c
for (initialization; condition; increment / decrement operation)
```

Below is an example of the use of `for` loop.

```c
#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 10; i ++) {
        printf("i %d\n", i);
    }

    return 0;
}
```

the `i = 0` statement in `for` executes only once. The `i < 10` statement executes everytime the loop repeats. The `i ++` statement executes everytime the statements in
the `for` loop executes.

The above `while (1)` can be re-written with `for` as follows.

```c
#include <stdio.h>

int main()
{
    int i = 0;

    for (;;) {
        if (i >= 10) {
            break;
        }
        printf("i %d\n", i);
        i ++;
    }

    return 0;
}
```

**3. Goto statement**

The statement `goto` is similar to a jump instruction in assembly. The above loop can be rewritten with `goto` as follows.


```c
#include <stdio.h>

int main()
{
    int i = 0;

begin:
    if (i < 10) {
        printf("i %d\n", i);
        i ++;
        goto begin;
    }

    return 0;
}
```

We do not use `goto` in most of the programs for the following reasons:

1. Readability reduces with many gotos with in a function or within a C file.
2. Incorrectly written gotos can cause loops in program.

Gotos are not bad when used correctly in a program. For example in usecases when certain conditions fail during a program initialization, the deinitialization sequence
must do the opposite. In such cases a jump required on the failure case.

Here's a pseudo code example,

```c
int init_1()
{
    ...
    return 0;
}

int init_2()
{
    ...
    return 0;
}

void deinit_1()
{
    ...
}

int init_main()
{
    int ret;

    ret = init_1();
    if (ret != 0) {
        return -1;
    }

    ret = init_2();
    if (ret != 0) {
        goto deinit;
    }

deinit:
    deinit_1();
    return -1;
}
```

More about functions in the `functions` section.

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

The size of an array is calculated the same way.

```c
#include <stdio.h>

int main()
{
    int a[10];

    printf("size of array %lu\n", sizeof(a));

    return 0;
}
```

With the `sizeof`, one can also find out the number of elements in the array as follows.

```c
#include <stdio.h>

int main()
{
    int a[10];

    printf("number of elements %d\n", sizeof(a) / sizeof(a[0]));

    return 0;
}
```

**Initializing array elements**

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

### Header description

The `stdint.h` from libc has further more data types. See `/usr/include/stdint.h`
The `limits.h` from libc contains all the ranges of the base types. See `/usr/include/limits.h`.

### Compilation of C program

### Command line arguments (argc, argv)

### File I/O

File I/O operations are exposed to the user by the libc. The libc indirectly calls the underlying system calls of the Operating system to manipulate the file. The File I/O APIs are declared in the `stdio.h`.

#### Basic operations

**1. Opening and Closing a file**

`FILE` is the structure implemented by the libc that is used in many of the file operations.

```c
FILE *fp;
```

denotes a file pointer of type `FILE`.

`fopen` is used to open the file. `fclose` is used to close the file.

the prototype of `fopen` is

```c
FILE *fopen(const char *filename, const char *mode);
```

the prototype of `fclose` is

```c
int fclose(FILE *fp);
```

Below example shows the use of `fopen` and `fclose` calls.

```c
#include <stdio.h>

int main()
{
    const char *filename = "./test.txt";
    FILE *fp;
    int ret = -1;

    fp = fopen(filename, "r");
    if (fp != NULL) {
        printf("file opened success\n");
        fclose(fp);
        ret = 0;
    } else {
        printf("file not found\n");
        ret = -1;
    }

    return ret;
}
```

**2. Reading from a File**

**3. Writing to a file**

#### Operating with the binary files

**1. Reading and Writing to a binary file**

### I/O operations


**1. Using fscanf, fgets and fprintf**


# C++ programming

## New operators in C++

**1. The Reference (`&`) operator.**

## New keywords in C++

#### constexpr

#### auto

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

C++ implements abstraction of threads based upon the pthreads. The class `std::thread` defines the thread interface.

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
