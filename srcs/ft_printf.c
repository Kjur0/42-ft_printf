/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 18:05:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_printf_utils.h>

#include <stdarg.h>

/** @brief handle printf formatters
 *
 * @see ft_printf()
 * @see ft_putchar()
 * @see ft_putstr()
 * @see ft_putptr()
 * @see ft_putnbr()
 * @see ft_putunsigned()
 * @see ft_puthex()
 *
 * @internal helper for ft_printf()
 * @param fmt	formatter
 * @param args	variadic arguments list
 * @return number of characters printed
 */
static int	ft_printf_format(const char fmt, va_list args)
{
	if (fmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (fmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (fmt == 'u')
		return (ft_putunsigned(va_arg(args, unsigned)));
	else if (fmt == 'x')
		return (ft_puthex(va_arg(args, unsigned), 0));
	else if (fmt == 'X')
		return (ft_puthex(va_arg(args, unsigned), 1));
	else if (fmt != 0)
	{
		if (fmt != '%')
			ft_putchar('%');
		return (ft_putchar(fmt) + (fmt != '%'));
	}
	return (-1);
}

/** @brief print a formatted string to `STDOUT` substituting with correct data
 *
 * All formatters start with `%`, then are substituted with data passed as `...`
 *
 * Supported formatters:
 * | Formatter | `vararg` type    | description             |
 * |-----------|------------------|-------------------------|
 * | `%c`      | `char`           | character               |
 * | `%s`      | `char *`         | string                  |
 * | `%p`      | `void *`         | pointer (address)       |
 * | `%d`      | `int`            | decimal                 |
 * | `%i`      | `int`            | integer (signed)        |
 * | `%u`      | `unsigned int`   | unsigned integer        |
 * | `%x`      | `unsigned int`   | hexadecimal (lowercase) |
 * | `%X`      | `unsigned int`   | hexadecimal (uppercase) |
 * | `%%`      | `void` (nothing) | percent (escaped)       |
 *
 * Bonus adds support for following flags
 * (added in between of `%` and specifier):
 * | Flag | Description                           |
 * |------|---------------------------------------|
 * | `-`  | align left                            |
 * | `0`  | zero pad (numbers)                    |
 * | `.`  | precision                             |
 * | `#`  | alternate format (hex with `0x`/`0X`) |
 * | ` `  | leave space for sign (signed numbers) |
 * | `+`  | always print sign (signed numbers)    |
 *
 * Bonus also adds support for minimum width.
 * It is represented as any decimal number in flags.
 * By default data is aligned to right.
 *
 * Flags requiring length:
 * * `-`
 * * `0`
 * * `.`
 *
 * @param str	format string
 * @param ...	variadic arguments for substitution
 * @return total length printed to console
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		chars;
	int		tmp;

	chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			tmp = ft_printf_format(*++str, args);
			if (tmp == -1)
			{
				va_end(args);
				return (-1);
			}
			chars += tmp;
			str++;
			continue ;
		}
		ft_putchar_fd(*str++, 1);
		chars++;
	}
	va_end(args);
	return (chars);
}
