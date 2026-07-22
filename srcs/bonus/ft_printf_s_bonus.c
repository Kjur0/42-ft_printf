/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:53:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 14:20:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

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
 * @param flags flags for printing
 */
void	ft_printf_s(char *s, t_list **lst, t_printf_flags flags)
{
	const int	len = ft_strlen(s);

	if (!s)
	{
		if (flags.precision > 5 || flags.precision == -1)
			ft_printf_s("(null)", lst, flags);
		return ;
	}
	if (flags.precision == -1)
		flags.precision = len;
	if (flags.min_width > flags.precision)
		flags.min_width -= flags.precision;
	else
		flags.min_width = 0;
	while (!flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
	while (*s && flags.precision-- > 0)
		ft_lst_char(lst, *s++);
	while (flags.align_left && flags.min_width--)
		ft_lst_char(lst, ' ');
}
