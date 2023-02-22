/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:52:44 by bamrouch          #+#    #+#             */
/*   Updated: 2023/02/22 20:59:49 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_garbage_collector.h"



int	main(void)
{
	int fd = open("./test.txt",O_RDONLY) ;


	char *p;
	while ((p = get_next_line(fd)))
		ft_printf("|%s|\n",p);
	ft_print_memory();
}
