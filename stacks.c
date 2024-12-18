/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:35 by ylabussi          #+#    #+#             */
/*   Updated: 2024/12/18 23:58:53 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stack_rot(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		ft_putendl_fd("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1);
		ft_lstlast(*lst)->next = *lst;
		(*lst)->next = NULL;
		*lst = tmp;
	}
}

void	stack_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*tmp;

	if (lst_from && lst_to)
	{
		tmp = *lst_from;
		lst_from = &(*lst_from)->next;
		ft_lstadd_front(lst_to, tmp);
	}
}

t_list	*arr_to_list(int *arr, size_t l)
{
	t_list	*lst;

	lst = NULL;
	while (l > 0)
	{
		l--;
		ft_lstadd_front(&lst, ft_lstnew(&arr[l]));
	}
	return (lst);
}