/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/17 22:40:33 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gargbage_collector.h"

t_list	*memory_root(void)
{
	static t_list *memory_root;

	return memory_root;
}

void	mem_add_node_to_scope(void *ptr,void *ref_pointer,uint64_t scope);
{
	t_list		*memory_scope;
	uint64_t	memory_scope_key; 

	memory_scope = memory_root();
	while (memory_scopes)
	{
		memory_scope_key = *(uint64_t)memory_scopes->content->content->scope;
		if (memory_scope_key == scope)
			break;
		memory_scopes = memory_scopes->next;
	}
	// Handle pointer addage;
	ft_lstadd_back(&memory_scope->content,ptr);
}

void	mem_add_new_scope(void *ptr,uint64_t scope);

void	*ft_malloc(uint64_t size, uint64_t scope, void (*f)(void *, ...))
{
	void	*temp;
	t_list	*temp_l;

	if (!size)
		return NULL;
	temp = malloc(size);
	if (!temp)
		return NULL;
}


