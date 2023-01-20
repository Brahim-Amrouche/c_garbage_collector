/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:52:44 by bamrouch          #+#    #+#             */
/*   Updated: 2023/01/20 18:54:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_garbage_collector.h"

int	main(void)
{
	int	*x;

	x = ft_malloc((sizeof(int) * 5), mem_pass_params(1, NULL, 0));
	ft_malloc((sizeof(int) * 3), mem_pass_params(1, x, 0));
	x = ft_malloc((sizeof(int) * 3), mem_pass_params(2, NULL, 0));
}
