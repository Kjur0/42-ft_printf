/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:44:58 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 10:57:48 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

/** @brief calculate length of unsigned integer in hexadecimal
 *
 * @internal helper for ft_printf_x()
 * @param nbr	unsigned integer
 * @return length of unsigned integer
 */
static int	ft_hex_len(unsigned int nbr)
{
	int	len;

	len = 1;
	nbr /= 0x10;
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
 * @param flags flags for printing
 * @param c		`'x'` or `'X'` for determining case
 */
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
