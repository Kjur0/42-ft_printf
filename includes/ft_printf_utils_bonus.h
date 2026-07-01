/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:09:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/01 20:57:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_BONUS_H
# define FT_PRINTF_UTILS_BONUS_H

# include <ft_printf.h>
# include <ft_printf_flags_bonus.h>

void	ft_printf_c(char c, t_list **lst, t_printf_flags flags);
void	ft_printf_s(char *s, t_list **lst, t_printf_flags flags);
void	ft_printf_p(void *p, t_list **lst, t_printf_flags flags);
void	ft_printf_di(int i, t_list **lst, t_printf_flags flags);
void	ft_printf_u(unsigned int u, t_list **lst, t_printf_flags flags);
void	ft_printf_x(unsigned int x, t_list **lst, t_printf_flags flags, char c);

typedef struct s_char
{
	char	c;
}	t_char;

void	ft_lst_char(t_list **lst, char c);
void	ft_lst_str(t_list **lst, char *str);

#endif
