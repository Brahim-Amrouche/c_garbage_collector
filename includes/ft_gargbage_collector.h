/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gargbage_collector.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:27 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/19 19:24:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR
#define FT_GARBAGE_COLLECTOR
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include "libft.h"

typedef struct s_mem_manage_params
{
    t_list *node;
    uint64_t scope;
    void *ref_pointer;
} t_mem_manage_params;

#endif