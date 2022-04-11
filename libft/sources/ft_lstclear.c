/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:18 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/03 15:51:14 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*t;

	if (!lst)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		free(*lst);
		(*lst) = t;
	}
	t = NULL;
}
