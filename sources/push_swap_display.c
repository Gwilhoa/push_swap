/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:07:52 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/03 16:14:35 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_get_index(t_list *lst, int index)
{
	int	i;
	int	ret;

	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	ret = lst->content;
	return (ret);
}

int	lst_get_top(t_list *lst)
{
	int	ret;

	ret = lst->content;
	return (ret);
}

int	lst_get_bottom(t_list *lst)
{
	int	ret;

	while (lst->next)
	{
		ret = lst->content;
		lst = lst->next;
	}
	ret = lst->content;
	return (ret);
}

int	compare(int nb, const char *str)
{
	char	*line;
	int		i;

	line = ft_itoa(nb);
	if (ft_strncmp(line, str, ft_strlen(str))
		&& ft_strncmp(str, "-0", 2))
		i = 0;
	else
		i = 1;
	free(line);
	return (i);
}
