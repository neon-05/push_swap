/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:33:51 by ylabussi          #+#    #+#             */
/*   Updated: 2024/12/18 15:20:40 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "stacks.h"

int		main(int argc, char const *argv[]);
int		*bubble_sort(int *arr, int l);
void	stack_sorting(int *arr_s, int *arr_t, size_t len);

int	main(int argc, char const *argv[])
{
	int	*arr_s;
	int	*arr_t;
	int	*arr_jmp;
	int	i;

	arr_s = malloc(sizeof(int) * (argc - 1));
	arr_t = malloc(sizeof(int) * (argc - 1));
	arr_jmp = malloc(sizeof(int) * (argc - 1));
	if (!arr_s || !arr_t || !arr_jmp)
		perror("Error\n");
	i = 0;
	while (i < argc - 1)
	{
		arr_s[i] = ft_atoi((char *) argv[i + 1]);
		arr_t[i] = arr_s[i];
		i++;
	}
	bubble_sort(arr_t, argc - 1);
	// i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("%i\t: s[%i] (%i)\t-> t[%i] (%i)\n", arr_s[i], i, arr_s[i], i + arr_jmp[i], arr_t[i + arr_jmp[i]]);
	// 	i++;
	// }

	// i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("t[%i] = %i\n", i, arr_t[i]);
	// 	i++;
	// }
	stack_sorting(arr_s, arr_t, argc - 1);
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
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
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
	else if ((int *) lst->content != target)
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

void	stack_sorting(int *arr_s, int *arr_t, size_t len)
{
	size_t	i;

	i = 0;
	
}
