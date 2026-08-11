/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:48:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:56:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_flags_bonus.h"

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
	flags->align_left = false;
	flags->alternate = false;
	flags->min_width = -1;
	flags->pad_zero = false;
	flags->precision = -1;
	flags->sign = false;
	flags->space = false;
	return (flags);
}
