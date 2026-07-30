/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:40:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/30 12:29:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAGS_BONUS_H
# define FT_PRINTF_FLAGS_BONUS_H

# include <ft_printf.h>

# include <stdbool.h>

/** @brief struct for storing flags
 *
 * @internal
*/
typedef struct s_printf_flags
{
	bool	align_left; ///< whether to align left (`-`)
	int		precision; ///< what precision is set (`.<width>`)
	bool	pad_zero; ///< whether to pad with zeros (`0`)
	int		min_width; ///< minimum width (`<width>`)
	bool	alternate; ///< whether to use alternate version (`#`)
	bool	space; ///< whether to leave space for sign (` `)
	bool	sign; ///< whether to always print sign (`+`)
}	t_printf_flags;

/** @brief create new ::t_printf_flags with default values
 *
 * @internal
 * @return default ::t_printf_flags
*/
t_printf_flags	*new_printf_flags(void);

#endif
