/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_managers_helpers_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:19:30 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/20 18:34:06 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

void	mem_cut_node(t_list *memory_scope, t_list *to_cut_node)
{
	t_list	*current_node;
	t_list	*prev_node;

	prev_node = memory_scope->content;
	current_node = prev_node->next;
	while (current_node && current_node != to_cut_node)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}
	prev_node->next = current_node->next;
}
