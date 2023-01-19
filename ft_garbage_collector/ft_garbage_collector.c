/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/19 20:20:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gargbage_collector.h"

t_list	*memory_root(void)
{
	static t_list *memory_root;

	return memory_root;
}

// finds a reference pointer this case is very important for included pointers for example **p includes *p so they need to be related
t_list	*mem_find_ref_pointers(t_list *memory_scope, void *ref_pointer)
{
	t_list *mem_scope_inner_nodes;
	t_list *current_node;
	
	mem_scope_inner_nodes = memory_scope->content;
	mem_scope_inner_nodes = mem_scope_inner_nodes->next;
	while (mem_scope_inner_nodes)
	{
		current_node = mem_scope_inner_nodes->content;
		while (current_node && current_node->content != ref_pointer)
			current_node = current_node->next;
		if (!current_node)
			mem_scope_inner_nodes = mem_scope_inner_nodes->next;
		return mem_scope_inner_nodes;
	}
	return memory_scope;
}

// use only with basic data types dont expected it to free inner mallocs
t_list *create_node_with_content(void *content)
{
	t_list *new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return NULL;
	}
	return new_node;
}

t_list	*mem_add_new_scope(uint64_t scope)
{
	uint64_t *key;
	t_list *scope_first_node;
	t_list *scope_node;
	t_list *mem_root;

	key = malloc(sizeof(uint64_t));
	if (!key)
		return NULL;
	*key = scope;
	scope_first_node = create_node_with_content(key);
	if (!scope_first_node)
		return NULL;
	scope_node = ft_lstnew(scope_first_node);
	if (!scope)
	{
		ft_lstclear(&scope_first_node, free);
		return NULL;
	}
	mem_root = memory_root();
	ft_lstadd_back(&mem_root, scope_node);
	return scope_node;
}

void	mem_add_node_to_scope(t_mem_manage_params params)
{
	t_list		*memory_scopes;
	uint64_t	memory_scope_key;
	t_list		*scope_node;

	memory_scopes = memory_root();
	while (memory_scopes)
	{
		memory_scope_key = *(uint64_t *)((t_list *) memory_scopes->content)->content;
		if (memory_scope_key == params.scope)
			break;
		memory_scopes = memory_scopes->next;
	}
	if(!memory_scopes)
		memory_scopes = mem_add_new_scope(params.scope);
	if (params.ref_pointer)
		memory_scopes = mem_find_ref_pointers(memory_scopes, params.ref_pointer);
	scope_node = memory_scopes->content;
	ft_lstadd_back(&scope_node, params.node);
}

void	*ft_malloc(uintptr_t size, t_mem_manage_params params, void (*f)(t_mem_manage_params))
{
	void	*temp;
	t_list	*temp_l;

	if (!size)
		return NULL;
	temp = malloc(size);
	if (!temp)
		return NULL;
	temp_l = create_node_with_content(temp);
	if (!temp)
		return NULL;
	f(params);
	return temp;
}


// time to test adding nodes and scopes and seeing if the structures are safe
int main(void)
{
	
}
