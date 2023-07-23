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

# C programming

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

## Control statements

## Loops


## Strings

## Arrays

**1. One Dimensional Arrays**

**2. Two Dimensional Arrays**

**3. Three Dimensional Arrays**

## Structures

### Bit fields

## Unions

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

## Appendix

The `stdint.h` from libc has further more data types.

### File I/O

#### Basic operations

**1. Opening and Closing a file**

**2. Reading from a File**

**3. Writing to a file**

#### Operating with the binary files


### I/O operations


# C++ programming

## Classes

Classes in C++ are similar to the structures in C. The Class is enclosure for data and operations on the data.

## Polymorphism

## Inheritance

### Simple Inheritance

### Multiple inheritance

### Abstract Classes


## Design Patterns
