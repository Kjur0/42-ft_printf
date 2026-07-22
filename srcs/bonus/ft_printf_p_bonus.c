/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:28:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 17:10:28 by kjurkows         ###   ########.fr       */
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
 * @param f	flags for printing
 */
void	ft_printf_p(void *p, t_list **lst, t_printf_flags *f)
{
	const int	len = ft_hex_len((size_t)p);

	if (f->pad_zero && f->precision == -1)
		f->precision = f->min_width - 2;
	if (len > f->precision)
		f->precision = len + (p == 0) * 3;
	if (f->precision + 2 + (f->sign || f->space) < f->min_width)
		f->min_width -= f->precision + 2 + (f->sign || f->space);
	else
		f->min_width = 0;
	while (!f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
	if (f->sign && p != 0)
		ft_lst_char(lst, '+');
	else if (f->space && p != 0)
		ft_lst_char(lst, ' ');
	if (p != 0)
		ft_lst_str(lst, "0x");
	while (f->precision-- > len && p != 0)
		ft_lst_char(lst, '0');
	ft_print_hex((size_t) p, lst);
	while (f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
}
