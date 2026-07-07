/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:11:31 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 10:44:15 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils.h>

/** @brief print character onto screen
 *
 * handles: `%c`
 *
 * @internal
 * @param c character to print
 * @return number of characters printed
 */
int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/** @brief print string onto screen
 *
 * handles: `%s`
 *
 * @internal
 * @param str string to print
 * @return number of characters printed
 */
int	ft_putstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

/** @brief print address onto screen
 *
 * @internal helper for ft_putptr()
 * @param ptr address to print
 * @return number of characters printed
 */
static int	ft_putaddress(size_t ptr)
{
	int		res;
	char	c;
	int		ret;

	ret = 0;
	if (ptr > 0xF)
		ret += ft_putaddress(ptr / 0x10);
	res = ptr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else
		c = 'a' + res - 0xA;
	ft_putchar_fd(c, 1);
	return (ret + 1);
}

/** @brief print pointer's address onto screen
 *
 * handles: `%p`
 *
 * @internal
 * @param ptr pointer which address to print
 * @return number of characters printed
 */
int	ft_putptr(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ft_putaddress((size_t)ptr) + 2);
}

/** @brief print number onto screen
 *
 * handles: `%d`, `%i`
 *
 * @internal
 * @param nbr number to print
 * @return number of characters printed
 */
int	ft_putnbr(int nbr)
{
	char	c;
	int		ret;

	ret = 0;
	if (nbr < 0)
	{
		ret++;
		ft_putchar_fd('-', 1);
		if (nbr < -9)
			ret += ft_putnbr(-(nbr / 10));
		c = '0' - nbr % 10;
	}
	if (nbr > 9)
		ret += ft_putnbr(nbr / 10);
	if (nbr >= 0)
		c = '0' + nbr % 10;
	ft_putchar_fd(c, 1);
	return (ret + 1);
}
