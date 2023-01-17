/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gargbage_collector.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:27 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/17 22:28:51 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR
#define FT_GARBAGE_COLLECTOR
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include "libft.h"

typedef struct s_mem_node
{
    void    *scope;
    t_list  *node;
}   t_mem_node;

#endif