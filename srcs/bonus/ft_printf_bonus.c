/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 17:21:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_printf_utils_bonus.h>

#include <stdarg.h>
#include <stdlib.h>

/** @brief get the width for a formatter
 *
 * @internal handles width reading ft_printf_format()
 * @param str pointer to current position in format string
 * @return parsed value
 */
static int	ft_printf_width(const char **str)
{
	int	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res = 10 * res + (*(*str)++ - '0');
	}
	(*str)--;
	return (res);
}

/** @brief print data substituting the formatter
 *
 * @see ft_printf_format()
 * @see ft_printf_c()
 * @see ft_printf_s()
 * @see ft_printf_p()
 * @see ft_printf_di()
 * @see ft_printf_u()
 * @see ft_printf_x()
 *
 * @internal
 * @param fmt	pointer to current position in format string
 * @param args	variadic arguments list
 * @param lst	pointer to linked list
*/
static int	ft_putfmt(const char **fmt, va_list args, t_list **lst,
	t_printf_flags *flags)
{
	if (**fmt == 'c')
		ft_printf_c(va_arg(args, int), lst, flags);
	else if (**fmt == 's')
		ft_printf_s(va_arg(args, char *), lst, flags);
	else if (**fmt == 'p')
		ft_printf_p(va_arg(args, void *), lst, flags);
	else if (**fmt == 'd' || **fmt == 'i')
		ft_printf_di(va_arg(args, int), lst, flags);
	else if (**fmt == 'u')
		ft_printf_u(va_arg(args, unsigned int), lst, flags);
	else if (**fmt == 'x' || **fmt == 'X')
		ft_printf_x(va_arg(args, unsigned int), lst, flags, **fmt);
	else if (**fmt == '%')
		ft_lst_char(lst, **fmt);
	else
	{
		(*fmt)++;
		free(flags);
		return (1);
	}
	(*fmt)++;
	free(flags);
	return (0);
}

/** @brief handle printf formatters and flags
 *
 * Printing is delegated to ft_putfmt()
 *
 * @see ft_printf()
 * @see ft_printf_width()
 * @see ft_putfmt()
 *
 * @internal helper for ft_printf()
 * @param fmt	pointer to current format string position
 * @param args	variadic arguments list
 * @param lst	pointer to linked list
 * @return number of characters printed
 */
static int	ft_printf_format(const char **fmt, va_list args, t_list **lst)
{
	t_printf_flags *const	flags = new_printf_flags();

	while (*++(*fmt))
	{
		if (**fmt == '-')
			flags->align_left = 1;
		else if (**fmt == '0')
			flags->pad_zero = 1;
		else if (**fmt == '.')
		{
			(*fmt)++;
			flags->precision = ft_printf_width(fmt);
		}
		else if (**fmt == '#')
			flags->alternate = 1;
		else if (**fmt == ' ')
			flags->space = 1;
		else if (**fmt == '+')
			flags->sign = 1;
		else if (ft_isdigit(**fmt))
			flags->min_width = ft_printf_width(fmt);
		else
			return (ft_putfmt(fmt, args, lst, flags));
	}
	return (1);
}

/** @brief print linked list
 *
 * @see ::t_char
 *
 * @internal helper for ft_printf
 * @param lst linked list to print
 * @return number of characters printed
*/
static int	ft_lst_print(t_list *lst)
{
	t_list	*next;
	int		size;

	size = 0;
	while (lst)
	{
		next = lst->next;
		size++;
		ft_putchar_fd(((t_char *)(lst->content))->c, 1);
		ft_lstdelone(lst, free);
		lst = next;
	}
	return (size);
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
	t_list	*lst;

	lst = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_printf_format(&str, args, &lst))
			{
				ft_lst_print(lst);
				return (-1);
			}
			continue ;
		}
		ft_lst_char(&lst, *str++);
	}
	va_end(args);
	return (ft_lst_print(lst));
}
