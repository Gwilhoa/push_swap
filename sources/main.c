/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/03 16:53:10 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list		*stacka;
	t_list		*stackb;
	t_list		*temp;
	const char	**args;

	temp = NULL;
	stacka = NULL;
	stackb = NULL;
	if (argc == 2 && ft_strlen(argv[1]) > 1)
		args = (const char **)ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (argc > 1 && ft_complete_args(args, &stacka, &temp) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
		return (1);
	}
	if (argc - 1 > 0 && !(lst_is_sort(stacka) == 1))
		tri(&stacka, &stackb);
	exit(EXIT_SUCCESS);
	return (argc);
}

int	lst_is_in(t_list *lst, int nb)
{
	while (lst)
	{
		if (lst->content == nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	lst_replace_index(t_list **lst, int index)
{
	int		i;
	t_list	*temp;
	t_list	*base;

	base = *lst;
	temp = base;
	i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	temp->content = INT_MAX;
	*lst = base;
	return ;
}

void	ft_initstack(t_list **temp, t_list **lst)
{
	int	*nbr;
	int	i;
	int	size;

	size = ft_lstsize(*temp);
	i = 0;
	nbr = ft_calloc(size, sizeof(int));
	if (lst_highest(*temp) == INT_MAX)
	{
		nbr[lst_highest_index(*temp)] = size;
		i++;
	}
	while (size > i)
	{
		nbr[lst_lowest_index(*temp)] = i;
		lst_replace_index(temp, lst_lowest_index(*temp));
		i++;
	}
	i = 0;
	while (size > i)
		lst_add_back(lst, nbr[i++]);
	free(nbr);
	return ;
}

int	ft_complete_args(char const **argv, t_list **lst, t_list **temp1)
{
	int		i;
	int		temp;

	i = -1;
	while (argv[++i])
	{
		temp = ft_atoi(argv[i]);
		if (compare(temp, argv[i]) == 0 || lst_is_in(*temp1, temp) == 1)
			return (0);
		lst_add_back(temp1, temp);
	}
	ft_initstack(temp1, lst);
	return (1);
}
