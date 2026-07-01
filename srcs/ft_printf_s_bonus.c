/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:53:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 17:48:53 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

void	ft_printf_s(char *s, t_list **lst, t_printf_flags flags)
{
	const int	len = ft_strlen(s);

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
