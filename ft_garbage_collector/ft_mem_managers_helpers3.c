/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_managers_helpers3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:47:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/02/21 18:54:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_garbage_collector.h"

void	ft_free_node(uint64_t scope, void *del_mem)
{
	t_list	*memory_scope;
	t_list	*move_node;
	t_list	*temp;

	if (scope == 0)
		return ;
	memory_scope = mem_find_scope(scope);
	move_node = mem_find_ref_pointers(memory_scope, del_mem);
	if (move_node == memory_scope)
		return ;
	mem_cut_node(memory_scope, move_node);
	while (move_node->content)
	{
		temp = ((t_list *)move_node->content)->next;
		free(((t_list *)move_node->content)->content);
		move_node->content = temp;
	}
	free(move_node);
	if (!((t_list *)memory_scope->content)->next)
		ft_free(scope, FALSE);
}
