/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:22:05 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/29 19:45:41 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>

/** @brief print a formatted string to `STDOUT` substituting with correct data
 *
 * All formatters start with `%`, then are substituted with data passed as `...`
 *
 * Supported formatters:
 * * `%c`
 * * `%s`
 * * `%p`
 * * `%d`
 * * `%i`
 * * `%u`
 * * `%x`
 * * `%X`
 * * `%%`
 *
 * Bonus adds support for following flags
 * (added in between of `%` and specifier):
 * * `-`
 * * `0`
 * * `.`
 * * `#`
 * * ` `
 * * `+`
 * * `<width>`
 *
 * Flags requiring length:
 * * `-`
 * * `0`
 * * `.`
 *
 * @param str	format string
 * @param ...	variadic arguments for substitution
 * @return total length printed to console
 */
int	ft_printf(const char *str, ...);

#endif
