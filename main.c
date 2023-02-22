/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:52:44 by bamrouch          #+#    #+#             */
/*   Updated: 2023/02/22 19:14:25 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_garbage_collector.h"



int	main(void)
{
	// int fd = open("./test.txt",O_RDONLY) ;


	// char *p;
	// // while ((p = get_next_line(fd)))
	// // 	ft_printf("|%s|",p);
	// p = get_next_line(fd);
	// ft_printf("|%s|",p);
	char *x = ft_malloc(sizeof(char)* 1, (t_mem_manage_params){NULL, 1 , NULL, 0});
	char *y = ft_malloc(sizeof(char)* 1, (t_mem_manage_params){NULL, 1 , NULL, 0});
	char *z = ft_malloc(sizeof(char)* 1, (t_mem_manage_params){NULL, 1 , NULL, 0});

	mem_move((t_mem_manage_params){NULL, 1, x, 2});
	ft_print_memory();
	mem_move((t_mem_manage_params){NULL, 1, z, 2});
	ft_print_memory();
}
