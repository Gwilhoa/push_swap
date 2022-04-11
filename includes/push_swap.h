/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwilhoa <gwilhoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/03 16:54:42 by gwilhoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

void	swap(t_list **lst, char c);
void	push(t_list **from, t_list **to, char c);
void	rotate(t_list **lst, char c);
void	reverse_rotate(t_list **lst, char c);

int		ft_complete_args(char const **argv, t_list **lst, t_list **temp1);
int		compare(int nb, const char *str);
int		lst_is_in(t_list *lst, int nb);
int		search_place(t_list *lst, int index);
int		lst_is_sort(t_list *lst);
int		lst_lowest_index(t_list *lst);
int		lst_highest_index(t_list *lst);
int		lst_highest(t_list *lst);
int		lst_get_index(t_list *lst, int index);
int		lst_get_top(t_list *lst);
int		lst_get_bottom(t_list *lst);
void	lst_scroll(t_list **lst, int size);
void	lst_add_back(t_list **lst, int nb);
void	lst_replace_index(t_list **lst, int index);
void	ft_initstack(t_list **temp, t_list **lst);

t_list	*get_top_link(t_list **lst);
t_list	*get_bottom_link(t_list **lst);

int		tri(t_list **stacka, t_list **stackb);
int		tri_three(t_list **stacka);
void	tri_main(t_list **stacka, t_list **stackb, int size);
int		tri_bubble(t_list **stacka, t_list **stackb);

int		lst_lowest(t_list *lst);
#endif
