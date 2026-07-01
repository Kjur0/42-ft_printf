*This project has been created as part of the 42 curriculum by **kjurkows***

# ft_printf

`libftprintf` is a custom implementation of the standard C `printf` function. It is designed to provide similar functionality while allowing for additional features and optimizations.

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
