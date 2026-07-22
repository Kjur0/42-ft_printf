/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:28:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 14:29:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

/** @brief calculate length of address in hexadecimal
 *
 * @internal helper for ft_printf_p()
 * @param ptr	address of a pointer
 * @return length of address
 */
static int	ft_hex_len(size_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= 0x10;
	}
	return (len);
}

/** @brief print address in hexadecimal
 *
 * @internal helper for ft_printf_p()
 * @param ptr	address of a pointer
 * @param lst	pointer to linked list
 */
static void	ft_print_hex(size_t ptr, t_list **lst)
{
	char	c;
	int		res;

	if (ptr == 0)
		return (ft_lst_str(lst, "(nil)"));
	if (ptr > 0xF)
		ft_print_hex(ptr / 0x10, lst);
	res = ptr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else
		c = 'a' + res - 0xA;
	ft_lst_char(lst, c);
}

/** @brief print pointer
 *
 * add pointer's address to linked list handling all necessary flags
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
 * @internal handler for `%p`
 * @param p		pointer which address to print
 * @param lst	pointer to linked list
 * @param flags	flags for printing
 */
void	ft_printf_p(void *p, t_list **lst, t_printf_flags flags)
{
	const int	len = ft_hex_len((size_t)p);

	if (flags.pad_zero && flags.precision == -1)
		flags.precision = flags.min_width - 2;
	if (len > flags.precision)
		flags.precision = len + (p == 0) * 3;
	if (flags.precision + 2 + (flags.sign || flags.space) < flags.min_width)
		flags.min_width -= flags.precision + 2 + (flags.sign || flags.space);
	else
		flags.min_width = 0;
	while (!flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
	if (flags.sign && p != 0)
		ft_lst_char(lst, '+');
	else if (flags.space && p != 0)
		ft_lst_char(lst, ' ');
	if (p != 0)
		ft_lst_str(lst, "0x");
	while (flags.precision-- > len && p != 0)
		ft_lst_char(lst, '0');
	ft_print_hex((size_t) p, lst);
	while (flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
}
