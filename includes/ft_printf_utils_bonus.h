/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:09:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/22 18:03:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_BONUS_H
# define FT_PRINTF_UTILS_BONUS_H

# include <ft_printf.h>
# include <ft_printf_flags_bonus.h>

# include <stdlib.h>

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
void	ft_printf_c(char c, t_list **lst, t_printf_flags *flags);
/** @brief print string
 *
 * add string to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `.`
 * * `<width`>
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%s`
 * @param s		string to print
 * @param lst	pointer to linked list
 * @param flags flags for printing
 */
void	ft_printf_s(char *s, t_list **lst, t_printf_flags *flags);
/** @brief print pointer
 *
 * add pointer's address to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 * * ` `
 * * `+`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%p`
 * @param p		pointer which address to print
 * @param lst	pointer to linked list
 * @param flags	flags for printing
 */
void	ft_printf_p(void *p, t_list **lst, t_printf_flags *flags);
/** @brief print digit/integer
 *
 * add integer's digits to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 * * ` `
 * * `+`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%d` & `%i`
 * @param i		integer to print
 * @param lst	pointer to linked list
 * @param flags	flags for printing
 */
void	ft_printf_di(int i, t_list **lst, t_printf_flags *flags);
/** @brief print unsigned integer
 *
 * add unsigned integer's digits to linked list handling all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%u`
 * @param u		unsigned integer to print
 * @param lst	pointer to linked list
 * @param flags	flags for printing
 */
void	ft_printf_u(unsigned int u, t_list **lst, t_printf_flags *flags);
/** @brief print hexadecimal
 *
 * add hexadecimal representation of unsigned integer to linked list handling
 * all necessary flags
 *
 * Supported flags:
 * * `-`
 * * `0`
 * * `.`
 * * `<width>`
 * * `#`
 *
 * @see ft_putfmt()
 * @see t_printf_flags
 *
 * @internal handler for `%x` & `%X`
 * @param x		unsigned integer to print
 * @param lst	pointer to linked list
 * @param flags flags for printing
 * @param c		`'x'` or `'X'` for determining case
 */
void	ft_printf_x(unsigned int x, t_list **lst, t_printf_flags *flags,
			char c);

/** @brief basic container for a character
 *
 * @internal
 */
typedef struct s_char
{
	char	c; ///< stored character
}	t_char;

/** @brief add character to linked list
 *
 * @internal
 * @param lst	pointer to linked list
 * @param c		character to add
 */
void	ft_lst_char(t_list **lst, char c);
/** @brief add characters from string to linked list
 *
 * @internal
 * @param lst	pointer to linked list
 * @param str	string with characters to add
 */
void	ft_lst_str(t_list **lst, char *str);

#endif
