/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:28:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 18:15:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

static int	ft_hex_len(size_t ptr)
{
	int	len;

	len = 1;
	ptr /= 0x10;
	while (ptr)
	{
		len++;
		ptr /= 0x10;
	}
	return (len);
}

static void	ft_print_hex(size_t ptr, t_list **lst)
{
	char	c;
	int		res;

	if (ptr > 0xF)
		ft_print_hex(ptr / 0x10, lst);
	res = ptr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else
		c = 'a' + res - 0xA;
	ft_lst_char(lst, c);
}

void	ft_printf_p(void *p, t_list **lst, t_printf_flags flags)
{
	const int	len = ft_hex_len((size_t)p);

	if (!p)
		return (ft_printf_s("(nil)", lst, flags));
	if (flags.pad_zero && flags.precision == -1)
		flags.precision = flags.min_width - 2;
	if (len > flags.precision)
		flags.precision = len;
	if (flags.precision + 2 + (flags.sign || flags.space) < flags.min_width)
		flags.min_width -= flags.precision + 2 + (flags.sign || flags.space);
	else
		flags.min_width = 0;
	while (!flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
	if (flags.sign)
		ft_lst_char(lst, '+');
	else if (flags.space)
		ft_lst_char(lst, ' ');
	ft_lst_str(lst, "0x");
	while (flags.precision-- > len)
		ft_lst_char(lst, '0');
	ft_print_hex((size_t) p, lst);
	while (flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
}
