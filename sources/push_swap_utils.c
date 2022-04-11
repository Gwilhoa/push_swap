/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:10:39 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 16:11:36 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_back(t_list **lst, int nb)
{
	ft_lstadd_back(lst, ft_lstnew(nb));
}

int	lst_is_sort(t_list *lst)
{
	t_list	*val;

	val = lst->next;
	while (val)
	{
		if (val->content < lst->content)
			return (0);
		val = val->next;
		lst = lst->next;
	}
	return (1);
}

t_list	*get_top_link(t_list **lst)
{
	t_list	*stack;

	stack = *lst;
	*lst = stack->next;
	stack->next = NULL;
	return (stack);
}

t_list	*get_bottom_link(t_list **lst)
{
	t_list	*stack;
	t_list	*temp;
	t_list	*temp2;

	stack = *lst;
	temp = stack;
	temp2 = temp->next;
	while (temp2->next)
	{
		temp2 = temp2->next;
		temp = temp->next;
	}
	temp->next = NULL;
	*lst = stack;
	return (temp2);
}
