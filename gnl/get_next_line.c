/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:53:38 by bamrouch          #+#    #+#             */
/*   Updated: 2023/02/21 16:44:00 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_garbage_collector.h"
#include <stddef.h>


static t_boolean    find_new_line(char *str)
{
    size_t i;

    i = 0;
    while (*(str + i) && *(str + i) != '\n')
        i++;
    if (*(str + i))
        return TRUE;
    return FALSE;
}

static char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1) + 1;
	total_len = s1_len + ft_strlen(s2);
	res = ft_malloc(total_len * sizeof(char), (t_mem_manage_params) {});
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, s1_len);
	ft_strlcat(res, s2, total_len);
	return (res);
}


static void gnl_helper(int fd, char **res)
{
    long    read_count;
    char    *buffer[BUFFER_SIZE];
           
    read_count = read(fd, buffer, BUFFER_SIZE);
    while (read_count >= 0 || *res)
    {
        *res = 
        if (read_count)
            
    }
    if (read_count == -1)
        ft_free(0, TRUE);
}


char *get_next_line(int fd)
{
    static char *res;

    if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
}

