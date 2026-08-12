/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:53:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/12 21:11:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

/** @brief print string
 *
 * add string to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `.`
 * * `<width`>
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%s`
 * @param s		string to print
 * @param lst	pointer to linked list
 * @param f		flags for printing
 */
void	ft_printf_s(char *s, t_list **lst, t_printf_flags *f)
{
	const int	len = ft_strlen(s);

	if (!s)
	{
		if (f->precision > 5 || f->precision < 0)
			ft_printf_s("(null)", lst, f);
		return ;
	}
	if (f->precision < 0)
		f->precision = len;
	if (f->min_width > f->precision)
		f->min_width -= f->precision;
	else
		f->min_width = 0;
	while (!f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
	while (*s && f->precision-- > 0)
		ft_lst_char(lst, *s++);
	while (f->align_left && f->min_width--)
		ft_lst_char(lst, ' ');
}
