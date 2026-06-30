/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:18:49 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/30 18:44:32 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf_utils.h>

int	ft_putunsigned(unsigned int nbr)
{
	char	c;
	int		ret;

	ret = 0;
	if (nbr > 9)
		ret += ft_putunsigned(nbr / 10);
	c = '0' + nbr % 10;
	ft_putchar_fd(c, 1);
	return (ret + 1);
}

int	ft_puthex(unsigned int nbr, int uppercase)
{
	int		res;
	char	c;
	int		ret;

	ret = 0;
	if (nbr > 0xF)
		ret += ft_puthex(nbr / 0x10, uppercase);
	res = nbr % 0x10;
	if (res <= 0x9)
		c = '0' + res;
	else
		c = 'a' + res - 0xA + (uppercase * ('A' - 'a'));
	ft_putchar_fd(c, 1);
	return (ret + 1);
}
