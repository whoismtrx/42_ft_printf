# ft_printf

![](https://github.com/whoismtrx/42_ft_printf/blob/main/ft_printf.gif)

## Overview

ft_printf is a project at 42 that aims to mimic the behavior of the original printf function. The project is written in C and is a part of the curriculum at 42. it's a great project to learn about variadic functions and how to parse and format strings.

## Key Features

The project contains 2 parts: `Mandatory` and `Bonus`. you need also create a `Makefile` to compile the project.
- `Mandatory` part is about implementing wihtout buufering the basic functionality of the printf function like conversion specifiers: `cspdiuxX%` and return the number of printed characters.
- `Bonus` part is about implementing the following conversion flags and manage with them all: `#0-+. ` yes the last character is a space.

## Getting Started

to compile the project you need to clone the repository first, to do that run the following command:
```
git clone https://github.com/whoismtrx/42_ft_printf.git ft_printf
cd ft_printf
make
```

## Usage

to use the ft_printf function you need to include the header file in your project:
```
// example.c
#include "ft_printf.h"
```
```
cc example.c libftprintf.a -o example
```

## Implementation

ft_printf function supports the following conversion specifiers, width and flags:

- `specifiers`:
	- `%` : print a `%` character.
	- `c` : print a character.
	- `s` : print a string.
	- `p` : print a pointer address.
	- `d` : print a decimal number.
	- `i` : print an integer.
	- `u` : print an unsigned integer.
	- `x` : print a hexadecimal number in lowercase.
	- `X` : print a hexadecimal number in uppercase.

- `width`:
	- `number` : set the width to the number.

- `flags`:
	- `#` : print the number in an alternative format.
	- `0` : print the number with leading zeros.
	- `-` : left-justify the number.
	- `+` : print the number with a sign.
	- `.` : print the number with a precision.
	- `space` : print the number with a space if no sign is printed.

## Resources

you can find some resources about the project in the following links:
- `variadic functions`: this is a great video about [variadic functions](https://www.youtube.com/watch?v=oDC208zvsdg&t=5s&ab_channel=CodeVault) and how to use them in C.
- `printf`: this is a great article about [printf](https://docs.oracle.com/cd/E26502_01/html/E28556/gkxbc.html), also you can read this pdf [Secrets of printf](https://inst.eecs.berkeley.edu/~cs61c/fa19/hw/hw2/printf_colton.pdf) to understand how printf works.