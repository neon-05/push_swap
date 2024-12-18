/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:58:31 by ylabussi          #+#    #+#             */
/*   Updated: 2024/12/18 23:11:11 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <libft.h>

void	stack_rot(t_list **lst);
void	stack_push(t_list **lst_from, t_list **lst_to);
t_list	*arr_to_list(int *arr, size_t l);

#endif
