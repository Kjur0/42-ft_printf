/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:48:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 10:48:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

/** @brief calculate length of integer in decimal
 *
 * @internal helper for ft_printf_di()
 * @param nbr	number
 * @return length of integer
 */
static int	ft_nbr_len(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
		len++;
	len /= 10;
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
		ft_lst_char(lst, '-');
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
 * @param flags	flags for printing
 */
void	ft_printf_di(int i, t_list **lst, t_printf_flags flags)
{
	const int	len = ft_nbr_len(i);

	if (flags.pad_zero && flags.precision == -1)
		flags.precision = flags.min_width;
	if (len > flags.precision)
		flags.precision = len;
	if (flags.precision + (flags.sign || flags.space) < flags.min_width)
		flags.min_width -= flags.precision + (flags.sign || flags.space);
	else
		flags.min_width = 0;
	while (!flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
	if (flags.sign && i >= 0)
		ft_lst_char(lst, '+');
	else if (flags.space && i >= 0)
		ft_lst_char(lst, ' ');
	while (flags.precision-- > len)
		ft_lst_char(lst, '0');
	ft_print_nbr(i, lst);
	while (flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
}
