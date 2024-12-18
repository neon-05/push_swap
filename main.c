/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:33:51 by ylabussi          #+#    #+#             */
/*   Updated: 2024/12/18 23:52:56 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "stacks.h"

int		main(int argc, char const *argv[]);
int		*bubble_sort(int *arr, int l);
void	stack_sorting(t_list *stack_a, t_list *stack_b, int *arr_t, size_t len);

int	main(int argc, char const *argv[])
{
	int	*arr_s;
	int	*arr_t;
	int	i;

	arr_s = malloc(sizeof(int) * (argc - 1));
	arr_t = malloc(sizeof(int) * (argc - 1));
	if (!arr_s || !arr_t)
	{
		perror("Error\n");
		exit(1);
	}
	i = 0;
	while (i < argc - 1)
	{
		arr_s[i] = ft_atoi((char *) argv[i + 1]);
		arr_t[i] = arr_s[i];
		i++;
	}
	bubble_sort(arr_t, argc - 1);
	stack_sorting(arr_to_list(arr_s, argc - 1), NULL, arr_t, argc - 1);
	return (0);
}

int	*bubble_sort(int *arr, int l)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < l - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	search_stack(t_list *lst, int target)
{
	int	r;

	if (lst)
		return (-1);
	else if (*(int *) lst->content != target)
	{
		r = search_stack(lst->next, target);
		if (r < 0)
			return (-1);
		else
			return (r + 1);
	}
	else
		return (0);
}

void	stack_sorting(t_list *stack_a, t_list *stack_b, int *arr_t, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len * 2)
	{
		while (stack_b && *(int *) stack_b->content != arr_t[i % len] && stack_b->next)
		{
			stack_rot(&stack_b);
			ft_putendl_fd("rb", 1);
		}
		if (stack_b && *(int *) stack_b->content == arr_t[i % len])
		{
			stack_push(&stack_b, &stack_a);
			ft_putendl_fd("pa", 1);
		}
		if (*(int *) stack_a->content == arr_t[i % len])
		{
			stack_rot(&stack_a);
			ft_putendl_fd("ra", 1);
		}
		else
		{
			stack_push(&stack_a, &stack_b);
			ft_putendl_fd("pb", 1);
		}
		if (*(int *) stack_a->content == arr_t[i % len])
		{
			stack_rot(&stack_a);
			ft_putendl_fd("ra", 1);
		}
		i++;
	}
}
