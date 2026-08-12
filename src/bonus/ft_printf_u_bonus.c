/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:28:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/12 21:11:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

/** @brief calculate length of unsigned integer in decimal
 *
 * @internal helper fot ft_printf_u()
 * @param nbr	unsigned integer
 * @return length of unsigned integer
 */
static int	ft_nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

/** @brief print unsigned integer in decimal
 *
 * @internal helper for ft_printf_u()
 * @param nbr	unsigned integer to print
 * @param lst	pointer to linked list
 */
static void	ft_print_nbr(unsigned int nbr, t_list **lst)
{
	char	c;

	if (nbr > 9)
		ft_print_nbr(nbr / 10, lst);
	c = '0' + nbr % 10;
	ft_lst_char(lst, c);
}

/** @brief print unsigned integer
 *
 * add unsigned integer's digits to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%u`
 * @param u		unsigned integer to print
 * @param lst	pointer to linked list
 * @param f		flags for printing
 */
void	ft_printf_u(unsigned int u, t_list **lst, t_printf_flags *f)
{
	const int	len = ft_nbr_len(u);

	if (!f->align_left && f->pad_zero && f->precision < 0)
		f->precision = f->min_width;
	if (len > f->precision)
		f->precision = len + (u == 0);
	if (f->precision < f->min_width)
		f->min_width -= f->precision ;
	else
		f->min_width = 0;
	while (!f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
	while (f->precision-- > len)
		ft_lst_char(lst, '0');
	if (u != 0)
		ft_print_nbr(u, lst);
	while (f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
}
