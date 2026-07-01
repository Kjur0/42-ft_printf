/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:44:58 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 19:29:12 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

static int	ft_hex_len(unsigned int ptr)
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

static void	ft_print_hex(size_t ptr, t_list **lst, int big)
{
	char	c;
	int		res;

	if (ptr > 0xF)
		ft_print_hex(ptr / 0x10, lst, big);
	res = ptr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else if (big)
		c = 'A' + res - 0xA;
	else
		c = 'a' + res - 0xA;
	ft_lst_char(lst, c);
}

void	ft_printf_x(unsigned int x, t_list **lst, t_printf_flags f, char c)
{
	const int	len = ft_hex_len(x);

	if (f.pad_zero && f.precision == -1)
		f.precision = f.min_width - (f.alternate && x != 0) * 2;
	if (len > f.precision)
		f.precision = len;
	if (f.precision + 2 * (f.alternate && x != 0) < f.min_width)
		f.min_width -= f.precision + 2 * (f.alternate && x != 0);
	else
		f.min_width = 0;
	while (!f.align_left && f.min_width--)
		ft_lst_char(lst, ' ');
	if (f.alternate && x != 0 && c == 'x')
		ft_lst_str(lst, "0x");
	else if (f.alternate && x != 0 && c == 'X')
		ft_lst_str(lst, "0X");
	while (f.precision-- > len)
		ft_lst_char(lst, '0');
	ft_print_hex(x, lst, c == 'X');
	while (f.align_left && f.min_width--)
		ft_lst_char(lst, ' ');
}
