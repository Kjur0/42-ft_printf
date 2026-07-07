/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:36:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 10:43:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

/** @brief print character
 *
 * add character to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `<width>`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%c`
 * @param c		character to print
 * @param lst	pointer to linked list
 * @param flags	flags for printing
 */
void	ft_printf_c(char c, t_list **lst, t_printf_flags flags)
{
	if (flags.align_left)
		ft_lst_char(lst, c);
	while (flags.min_width-- > 1)
		ft_lst_char(lst, ' ');
	if (!flags.align_left)
		ft_lst_char(lst, c);
}
