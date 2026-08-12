/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:48:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/12 21:10:57 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

/** @brief calculate length of integer in decimal
 *
 * @internal helper for ft_printf_di()
 * @param nbr	number
 * @return length of integer
 */
static int	ft_nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

/** @brief print integer in decimal
 *
 * @internal helper for ft_printf_di()
 * @param nbr	number
 * @param lst	pointer to linked list
*/
static void	ft_print_nbr(int nbr, t_list **lst)
{
	char	c;

	if (nbr < 0)
	{
		if (nbr < -9)
			ft_print_nbr(-(nbr / 10), lst);
		c = '0' - nbr % 10;
	}
	if (nbr > 9)
		ft_print_nbr(nbr / 10, lst);
	if (nbr >= 0)
		c = '0' + nbr % 10;
	ft_lst_char(lst, c);
}

/** @brief print digit/integer
 *
 * add integer's digits to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 * * ` `
 * * `+`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%d` & `%i`
 * @param i		integer to print
 * @param lst	pointer to linked list
 * @param f		flags for printing
 */
void	ft_printf_di(int i, t_list **lst, t_printf_flags *f)
{
	const int	len = ft_nbr_len(i);

	f->precision += i < 0;
	if (!f->align_left && f->pad_zero && f->precision < 0)
		f->precision = f->min_width;
	if (len > f->precision)
		f->precision = len + (i == 0);
	if (f->precision + ((f->sign || f->space) && i > 0) < f->min_width)
		f->min_width -= f->precision + ((f->sign || f->space) && i > 0);
	else
		f->min_width = 0;
	while (!f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
	if (f->sign && i >= 0)
		ft_lst_char(lst, '+');
	else if (f->space && i >= 0)
		ft_lst_char(lst, ' ');
	if (i < 0)
		ft_lst_char(lst, '-');
	while (f->precision-- > len)
		ft_lst_char(lst, '0');
	if (i != 0)
		ft_print_nbr(i, lst);
	while (f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
}
