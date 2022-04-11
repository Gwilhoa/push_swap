/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:39:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 16:42:46 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list	*top;
	t_list	*second;

	top = get_top_link(lst);
	second = get_top_link(lst);
	ft_lstadd_front(lst, top);
	ft_lstadd_front(lst, second);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	push(t_list **from, t_list **to, char c)
{
	ft_lstadd_front(to, get_top_link(from));
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate(t_list **lst, char c)
{
	ft_lstadd_back(lst, get_top_link(lst));
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	reverse_rotate(t_list **lst, char c)
{
	ft_lstadd_front(lst, get_bottom_link(lst));
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
