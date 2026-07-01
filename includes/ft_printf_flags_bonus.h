/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:40:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 18:49:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAGS_BONUS_H
# define FT_PRINTF_FLAGS_BONUS_H

typedef struct s_printf_flags
{
	int	align_left;
	int	precision;
	int	pad_zero;
	int	min_width;
	int	alternate;
	int	space;
	int	sign;
}	t_printf_flags;

t_printf_flags	new_printf_flags(void);
int				any_printf_flags(t_printf_flags flags);

#endif
