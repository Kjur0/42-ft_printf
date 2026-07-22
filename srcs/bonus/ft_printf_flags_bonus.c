/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:48:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 17:05:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_flags_bonus.h>

#include <stdlib.h>

/** @brief create new ::t_printf_flags with default values
 *
 * @internal
 * @return default ::t_printf_flags
*/
t_printf_flags	*new_printf_flags(void)
{
	t_printf_flags	*flags;

	flags = malloc(sizeof(t_printf_flags));
	flags->align_left = 0;
	flags->alternate = 0;
	flags->min_width = -1;
	flags->pad_zero = 0;
	flags->precision = -1;
	flags->sign = 0;
	flags->space = 0;
	return (flags);
}
