/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/18 21:59:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_gargbage_collector.h"

t_list	*memory_root(void)
{
	static t_list *memory_root;

	return memory_root;
}

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

// use only with basic data types
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
	t_list *scope;
	t_list *mem_root;

	key = malloc(sizeof(uint64_t));
	if (!key)
		return NULL;
	*key = scope;
	scope_first_node = create_node_with_content(key);
	if (!scope_first_node)
		return NULL;
	scope = ft_lstnew(scope_first_node);
	if (!scope)
	{
		ft_lstclear(&scope_first_node, free);
		return NULL;
	}
	mem_root = memory_root();
	ft_lstadd_back(&mem_root, scope);
}

void	mem_add_node_to_scope(t_list *ptr, uint64_t scope, void *ref_pointer)
{
	t_list		*memory_scopes;
	uint64_t	memory_scope_key; 

	memory_scopes = memory_root();
	while (memory_scopes)
	{
		memory_scope_key = *(uint64_t *)((t_list *) memory_scopes->content)->content;
		if (memory_scope_key == scope)
			break;
		memory_scopes = memory_scopes->next;
	}
	if(!memory_scopes)
		memory_scopes = mem_add_new_scope(scope);
	if (ref_pointer)
		memory_scopes = mem_find_ref_pointers(memory_scopes, ref_pointer);
	ft_lstadd_back(&memory_scopes->content,ptr);
}


void	*ft_malloc(uintptr_t size, uint64_t scope, void (*f)(void *, ...))
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
	// here all memory function will accept a struct parameter 
	// && for Cursus purposes a function that creates that type should be made
	f(temp_l);
}


