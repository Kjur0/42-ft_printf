/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/29 19:46:12 by kjurkows         ###   ########.fr       */
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
	if (fmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (fmt == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (fmt == 'u')
		return (ft_putunsigned(va_arg(args, unsigned)));
	if (fmt == 'x')
		return (ft_puthex(va_arg(args, unsigned), 0));
	if (fmt == 'X')
		return (ft_puthex(va_arg(args, unsigned), 1));
	if (fmt == '%')
		return (ft_putchar('%'));
	return (-1);
}

/** @brief print a formatted string to `STDOUT` substituting with correct data
 *
 * All formatters start with `%`, then are substituted with data passed as `...`
 *
 * Supported formatters:
 * * `%c`
 * * `%s`
 * * `%p`
 * * `%d`
 * * `%i`
 * * `%u`
 * * `%x`
 * * `%X`
 * * `%%`
 *
 * Bonus adds support for following flags
 * (added in between of `%` and specifier):
 * * `-`
 * * `0`
 * * `.`
 * * `#`
 * * ` `
 * * `+`
 * * `<width>`
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
