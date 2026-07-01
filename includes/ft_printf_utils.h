/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:50:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 20:57:23 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <libft.h>

/** @brief print character onto screen
 *
 * handles: `%c`
 *
 * @internal
 * @param c character to print
 * @return number of characters printed
 */
int	ft_putchar(char c);
/** @brief print string onto screen
 *
 * handles: `%s`
 *
 * @internal
 * @param str string to print
 * @return number of characters printed
 */
int	ft_putstr(char *str);
/** @brief print pointer's address onto screen
 *
 * handles: `%p`
 *
 * @internal
 * @param ptr pointer which address to print
 * @return number of characters printed
 */
int	ft_putptr(void *ptr);
/** @brief print number onto screen
 *
 * handles: `%d`, `%i`
 *
 * @internal
 * @param nbr number to print
 * @return number of characters printed
 */
int	ft_putnbr(int nbr);
/** @brief print unsigned number onto screen
 *
 * handles: `%u`
 *
 * @internal
 * @param nbr number to print
 * @return number of characters printed
 */
int	ft_putunsigned(unsigned int nbr);
/** @brief print hexadecimal number onto screen
 *
 * handles: `%x`, `%X`
 *
 * @internal
 * @param nbr		number to print
 * @param uppercase	whether to print it in uppercase
 * @return number of characters printed
 */
int	ft_puthex(unsigned int nbr, int uppercase);

#endif
