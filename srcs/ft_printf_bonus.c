/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 18:55:27 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

#include <stdarg.h>
#include <stdlib.h>

int	ft_printf_dig(const char **str)
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

void	ft_putfmt(const char **fmt, va_list args, t_list **lst,
	t_printf_flags flags)
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
	(*fmt)++;
}

void	ft_printf_format(const char **fmt, va_list args, t_list **lst)
{
	t_printf_flags	flags;

	flags = new_printf_flags();
	while (*++(*fmt))
	{
		if (**fmt == '-')
			flags.align_left = 1;
		else if (**fmt == '0')
			flags.pad_zero = 1;
		else if (**fmt == '.')
		{
			(*fmt)++;
			flags.precision = ft_printf_dig(fmt);
		}
		else if (**fmt == '#')
			flags.alternate = 1;
		else if (**fmt == ' ')
			flags.space = 1;
		else if (**fmt == '+')
			flags.sign = 1;
		else if (ft_isdigit(**fmt))
			flags.min_width = ft_printf_dig(fmt);
		else
			return (ft_putfmt(fmt, args, lst, flags));
	}
}

int	ft_lst_print(t_list *lst)
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
			ft_printf_format(&str, args, &lst);
			continue ;
		}
		ft_lst_char(&lst, *str++);
	}
	va_end(args);
	return (ft_lst_print(lst));
}
