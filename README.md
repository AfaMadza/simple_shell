# simple_shell
### Description
Holberton School's simple_shell ensures students grasp core concepts such as va_arg, va_list, and va_end. Other basic concepts such as loops, arrays, and structs were employed in the making of this function.

### Environment
This function was developed and tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

### File Contents
The repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| \_printf.c | The printf function |
| holberton.h   | Header file containing all function prototypes and struct declaration |
| digit_conversion.c| File containing an implementation of itoa which is used in the op_function file |
| utility.c | File contains useful implementations of functions such as putchar and strlen |
| op_function.c | File contains all functions used to write to standard output |



### Function Descriptions

| **Function** | **Description** |
| -------------- | ----------------- |
|int (*get_format(char chr))(va_list)| Function that checks if the character format modifier being passed is valid or not|
|int _putchar(char c)| Writes a character to stdout|
|int print_ch(va_list list)|prints a character|
|int print_st(va_list list)|Prints a string|
|int print_in(va_list list)|Prints an integer|
|int print_di(va_list list)|Prints a digit|
|int count_digit(int n)|Counts the digits in an integer|
|int _itoa(int n)|Converts each integer to its ASCII value|
|int _strlen(char *s|Returns the length of a string|

### Usage and Installation
Clone the repository, create a main.c file, then compile using gcc.
```
$ git clone https://github.com/AfaMadza/printf.git
```
### Compilation

This code was compiled with the following flags:
` $ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c -o _printf `

###### Example code

```
int main(void)
{
	_printf("Hello %s\n", "World");
		       return (0);
		       }
		       =========================================
		       $ ./printf
		       Hello World
		       $
		       ```

###  Roadmap
Adding flag character and conversion specifier functionality:
* l
* h
* field width for non-custom conversion specifiers.
* precision for non-custom conversion specifiers.

Adding more format modifiers:
* r
* R
* x
* X
* u
* o
* S
* p

### Authors

* [**Afa Madza**](https://github.com/AfaMadza)
* [**Alex Allen**](https://github.com/sanjurosaves)

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>