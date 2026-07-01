/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:48:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 18:49:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf_flags_bonus.h>

t_printf_flags	new_printf_flags(void)
{
	t_printf_flags	flags;

	flags.align_left = 0;
	flags.alternate = 0;
	flags.min_width = -1;
	flags.pad_zero = 0;
	flags.precision = -1;
	flags.sign = 0;
	flags.space = 0;
	return (flags);
}

int	any_printf_flags(const t_printf_flags flags)
{
	return (flags.align_left || flags.alternate || flags.min_width
		|| flags.pad_zero || flags.sign || flags.space);
}
