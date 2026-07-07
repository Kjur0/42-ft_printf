/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:22:05 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 11:58:55 by kjurkows         ###   ########.fr       */
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
 * | Formatter | `vararg` type    | description             |
 * |-----------|------------------|-------------------------|
 * | `%c`      | `char`           | character               |
 * | `%s`      | `char *`         | string                  |
 * | `%p`      | `void *`         | pointer (address)       |
 * | `%d`      | `int`            | decimal                 |
 * | `%i`      | `int`            | integer (signed)        |
 * | `%u`      | `unsigned int`   | unsigned integer        |
 * | `%x`      | `unsigned int`   | hexadecimal (lowercase) |
 * | `%X`      | `unsigned int`   | hexadecimal (uppercase) |
 * | `%%`      | `void` (nothing) | percent (escaped)       |
 *
 * Bonus adds support for following flags
 * (added in between of `%` and specifier):
 * | Flag | Description                           |
 * |------|---------------------------------------|
 * | `-`  | align left                            |
 * | `0`  | zero pad (numbers)                    |
 * | `.`  | precision                             |
 * | `#`  | alternate format (hex with `0x`/`0X`) |
 * | ` `  | leave space for sign (signed numbers) |
 * | `+`  | always print sign (signed numbers)    |
 *
 * Bonus also adds support for minimum width.
 * It is represented as any decimal number in flags.
 * By default data is aligned to right.
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
