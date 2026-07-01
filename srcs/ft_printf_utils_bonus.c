/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:30:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 18:12:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_utils_bonus.h>

#include <stdlib.h>

void	ft_lst_char(t_list **lst, char c)
{
	t_char	*cc;

	cc = malloc(sizeof(t_char));
	cc->c = c;
	ft_lstadd_back(lst, ft_lstnew(cc));
}

void	ft_lst_str(t_list **lst, char *str)
{
	while (*str)
		ft_lst_char(lst, *str++);
}
