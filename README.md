*This project has been created as part of the 42 curriculum by **kjurkows***

# ft_printf

`libftprintf` is a custom implementation of the standard C `printf` function. It is designed to provide similar functionality while allowing for additional features and optimizations.

> [!IMPORTANT]
> `ft_printf` requires presence of `libft` library.  
> By default it is directly embedded into the `libftprintf` library 

## Description

`ft_printf` is a variadic function that formats and prints data to the standard output. It supports a variety of format specifiers:

| Specifier | Description             | Type           |
|-----------|-------------------------|----------------|
| `%c`      | Character               | `char`         |
| `%s`      | String                  | `char *`       |
| `%p`      | Pointer                 | `void *`       |
| `%d`      | Digit                   | `int`          |
| `%i`      | Integer                 | `int`          |
| `%u`      | Unsigned integer        | `unsigned int` |
| `%x`      | Hexadecimal (lowercase) | `unsigned int` |
| `%X`      | Hexadecimal (uppercase) | `unsigned int` |
| `%%`      | Percent sign            | N/A            |

### Bonus features

> [!NOTE]
> Those are additional features that are not part of the mandatory requirements. To use them, you need to use `bonus` target.

Bonus implements support for variety of flags:

| Flag       | Description                                                 |
|------------|-------------------------------------------------------------|
| `-`        | Left-justify within the given field width                   |
| `0<width>` | Pad number with spaces (`width` is the minimum field width) |
| `.<width>` | Precision for numbers and strings (see [below](#precision)) |
| `<width>`  | Minimum field width, pad with spaces (left)                 |
| `#`        | Alternate form (see [below](#alternate-form))               |
| ` `        | Leave space for optional `-` sign                           |
| `+`        | Always show sign for numbers                                |

Flags can be used interchangeably, and their order does not matter (expect for `0` & `.`).  
The `0` flag is ignored if the `-` flag is present, and the `.` flag takes precedence over the `0` flag.

#### Precision

Precision works differently for numbers and strings:

##### Numbers

Precision specifies minimum number of digits to be printed. If the number of digits is less than the specified precision, the output is padded with leading zeros. If the number of digits is greater than or equal to the specified precision, the output is not affected.

##### Strings

Precision specifies the maximum number of characters to be printed. If the string is longer than the specified precision, it is truncated. If the string is shorter than the specified precision, it is not affected.

#### Alternate form

Alternate form is used to modify the output format for certain specifiers. For example, when using the `#` flag with the `%x` or `%X` specifier, it prefixes the output with `0x` or `0X`, respectively. Alternate form is ignored if the value is equal to `0` (zero).

## Instructions

### Compilation

To compile the `ft_printf` library, you can use the provided Makefile. Simply run the following command in your terminal:

```bash
make
```

#### Makefile Targets

| Target          | Description                                                  |
|-----------------|--------------------------------------------------------------|
| `all`           | Compiles the library and creates the `libftprintf.a` archive |
| `bonus`         | Creates the bonus features                                   |
| `clean`         | Removes object files                                         |
| `fclean`        | Removes object files and the `libftprintf.a` archive         |
| `re`            | Cleans and recompiles the library                            |

## Resources

* Peers
* `man`

### AI Usage

#### Google Gemini

Gemini was used as an aid in discovering different flags and format specifiers for bonus.

#### GitHub Copilot (via VS Code)

Copilot was used as an assist while creating documentation.

### Tools

Main used IDE was `Visual Studio Code`

[`norminette`](https://github.com/42school/norminette) was used to check **La Norme** compliance

`make`, `gcc` & `ar` are used while compiling the library.

## Algorithms and data structures

No specific algorithm or data structure is used for the mandatory (basic) project.

It stores the number of characters in a variable and prints everything as it is encountered in the format string, when a format specifier is encountered, it calls the appropriate function to handle the argument and print it.

Printing numbers is done recursively, and the number of printed characters are passed back as return values to the main function.
Printing strings is done by counting its length and printing it character by character.

### Bonus

#### Structures

A structure `s_printf_flags` is used to store formatter flags and their values.

A linked list is used to store all character to be printed. It utilizes special `s_char` as a basic container (it also ensures safety from segmentation faults).  
Usage of linked list allows to store all characters in the order they are encountered, and print them all at once at the end of the function. This is done to ensure that the output is printed in the correct order, and to avoid issues with padding and alignment.

#### Algorithms

Parsing the format string is done by iterating through each character:
* If it is a normal character, it is added to the linked list.
* If it is a start of a format specifier (`%`) a function is called to parse the specifier and its flags, and the appropriate function is called to handle the argument and print it.

Parsing flags is done by iterating through each character after the `%` until a valid specifier is found. Each flag is checked and stored in the `s_printf_flags` structure.

After specifier is found, the appropriate function is called to handle the argument and print it. The function uses the flags stored in the `s_printf_flags` structure to format the output.

Additionally parsing the flag works on the original `format` pointer, therefore there is no need to additionally update the pointer to the next character after the specifier, as it is already updated in the original pointer.

Printing each argument is done by calling the appropriate function for the specifier, which uses the flags stored in the `s_printf_flags` structure to format the output. The output is then added to the linked list.  
All handlers first ensure proper padding/alignment/precision, then add the characters to the linked list.  
Handlers for numbers use recursive helper functions to print the digits in the correct order, and handlers for strings use a loop to print each character.

Some handlers also use helpers that determine the length of the argument to be printed (for handling precision, alignment, and padding).  
These are either implemented as separate helper functions or use existing functions from the `libft` library.

Determining the length of any number is done by dividing the number by base until it reaches 0, and counting the number of divisions.  
Some helpers also ensure proper handling of negative numbers, and return the length of the number with the sign.

After the entire `format` string is parsed, the linked list is traversed:
* Each character is printed to the standard output.
* Each `char` container is freed after it is printed to avoid memory leaks. (`s_char`)
* Each node of the linked list is freed after it is printed to avoid memory leaks.
* The total number of printed characters is returned as the return value of the `ft_printf` function. (Length of the linked list)
