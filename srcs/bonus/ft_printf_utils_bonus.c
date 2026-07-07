/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:30:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/07 10:44:04 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

#include <stdlib.h>

/** @brief add character to linked list
 *
 * @internal
 * @param lst	pointer to linked list
 * @param c		character to add
 */
void	ft_lst_char(t_list **lst, char c)
{
	t_char	*cc;

	cc = malloc(sizeof(t_char));
	cc->c = c;
	ft_lstadd_back(lst, ft_lstnew(cc));
}

/** @brief add characters from string to linked list
 *
 * @internal
 * @param lst	pointer to linked list
 * @param str	string with characters to add
 */
void	ft_lst_str(t_list **lst, char *str)
{
	while (*str)
		ft_lst_char(lst, *str++);
}
