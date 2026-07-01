/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:36:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 17:48:59 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

void	ft_printf_c(char c, t_list **lst, t_printf_flags flags)
{
	if (flags.align_left)
		ft_lst_char(lst, c);
	while (flags.min_width-- > 1)
		ft_lst_char(lst, ' ');
	if (!flags.align_left)
		ft_lst_char(lst, c);
}
