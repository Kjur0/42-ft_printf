/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 20:56:52 by kjurkows         ###   ########.fr       */
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
	else if (fmt == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		chars;

	chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			chars += ft_printf_format(*++str, args);
			str++;
			continue ;
		}
		ft_putchar_fd(*str++, 1);
		chars++;
	}
	va_end(args);
	return (chars);
}
