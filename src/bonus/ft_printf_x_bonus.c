/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:44:58 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/12 21:12:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

/** @brief calculate length of unsigned integer in hexadecimal
 *
 * @internal helper for ft_printf_x()
 * @param nbr	unsigned integer
 * @return length of unsigned integer
 */
static int	ft_hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 0x10;
	}
	return (len);
}

/** @brief print unsigned integer in hexadecimal
 *
 * @internal helper for ft_printf_x()
 * @param nbr	unsigned integer to print
 * @param lst	pointer to linked list
 * @param big	whether to use uppercase
 */
static void	ft_print_hex(unsigned int nbr, t_list **lst, int big)
{
	char	c;
	int		res;

	if (nbr > 0xF)
		ft_print_hex(nbr / 0x10, lst, big);
	res = nbr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else if (big)
		c = 'A' + res - 0xA;
	else
		c = 'a' + res - 0xA;
	ft_lst_char(lst, c);
}

/** @brief print hexadecimal
 *
 * add hexadecimal representation of unsigned integer to linked list handling
 * all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 * * `#`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%x` & `%X`
 * @param x		unsigned integer to print
 * @param lst	pointer to linked list
 * @param f		flags for printing
 * @param uc	whether to use uppercase
 */
void	ft_printf_x(unsigned int x, t_list **lst, t_printf_flags *f, bool uc)
{
	const int	len = ft_hex_len(x);

	if (!f->align_left && f->pad_zero && f->precision < 0)
		f->precision = f->min_width - (f->alternate && x != 0) * 2;
	if (len > f->precision)
		f->precision = len + (x == 0);
	if (f->precision + 2 * (f->alternate && x != 0) < f->min_width)
		f->min_width -= f->precision + 2 * (f->alternate && x != 0);
	else
		f->min_width = 0;
	while (!f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
	if (f->alternate && x != 0 && !uc)
		ft_lst_str(lst, "0x");
	if (f->alternate && x != 0 && uc)
		ft_lst_str(lst, "0X");
	while (f->precision-- > len)
		ft_lst_char(lst, '0');
	if (x != 0)
		ft_print_hex(x, lst, uc);
	while (f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
}
