/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/20 18:50:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

// returns pointer towards the memory management root node
t_list	**memory_root(void)
{
	static t_list	*memory_root;

	return (&memory_root);
}

// adds an address to an existing scope 
//or creates a new scope then adds the memory to it
void	mem_manage_add(t_mem_manage_params params)
{
	t_list	*memory_scopes;
	t_list	*scope_node;

	memory_scopes = mem_find_scope(params.scope);
	if (!memory_scopes)
		memory_scopes = mem_add_new_scope(params.scope);
	if (params.ref_pointer)
		memory_scopes = mem_find_ref_pointers(memory_scopes,
				params.ref_pointer);
	else
		params.node = create_node_with_content(params.node);
	if (!params.node)
		return ;
	scope_node = memory_scopes->content;
	ft_lstadd_back(&scope_node, params.node);
}

// moves a memory ref from a scope to another
void	mem_manage_move(t_mem_manage_params params)
{
	t_list	*memory_scope;
	t_list	*move_node;
	t_list	*new_scope;

	if (params.scope == 0 || params.move_scope == 0)
		return ;
	memory_scope = mem_find_scope(params.scope);
	move_node = mem_find_ref_pointers(memory_scope, params.ref_pointer);
	if (move_node == memory_scope)
		return ;
	mem_cut_node(memory_scope, move_node);
	new_scope = mem_find_scope(params.move_scope)->content;
	ft_lstadd_back(&new_scope, move_node);
}

// generate a t_mem_params object : parameters goes as follows 
// uint64_t scope, void *ref_pointer, uint64_t move_scope
t_mem_manage_params	mem_pass_params(uint64_t scope, ...)
{
	va_list				params;
	t_mem_manage_params	res;

	va_start(params, scope);
	res.node = NULL;
	res.scope = scope;
	res.ref_pointer = va_arg(params, void *);
	res.move_scope = va_arg(params, uint64_t);
	va_end(params);
	return (res);
}

void	*ft_malloc(uint64_t size, t_mem_manage_params params)
{
	void	*temp;
	t_list	*temp_l;

	if (!size || params.scope == 0)
		return (NULL);
	temp = malloc(size);
	if (!temp)
		return (NULL);
	temp_l = create_node_with_content(temp);
	if (!temp_l)
	{
		free(temp);
		return (NULL);
	}
	params.node = temp_l;
	mem_manage_add(params);
	return (temp);
}
