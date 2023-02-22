/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:53:38 by bamrouch          #+#    #+#             */
/*   Updated: 2023/02/22 18:11:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

static long find_new_line(char *str)
{
    ssize_t i;

	if (!str)
		return -1;
    i = 0;
    while (*(str + i) && *(str + i) != '\n')
        i++;
    if (*(str + i))
        return i;
    return -1;
}

static size_t gnl_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return i;
	while (*(str + i))
		i++;
	return i;
}

size_t	gnl_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = gnl_strlen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = gnl_strlen(dst);
	i = 0;
	if (dstsize <= dst_len || dstsize == 0)
		return (src_len + dstsize);
	while (i < dstsize - dst_len - 1 && i < src_len)
	{
		dst[(dst_len + i)] = src[i];
		i++;
	}
	dst[(dst_len + i)] = '\0';
	return (src_len + dst_len);
}


static void gnl_strjoin(char **line, char *buffer)
{
	size_t	total_len;
	size_t	s1_len;
	char	*old_line;

    old_line = *line;
	s1_len = gnl_strlen(old_line);
	total_len = s1_len + gnl_strlen(buffer);
	*line = ft_malloc((total_len + 1) * sizeof(char), (t_mem_manage_params) {NULL, 2, NULL, 0});
	if (!(*line))
		return ;
	*line[0] = 0;
	gnl_strlcat(*line, old_line, s1_len);
    ft_free_node(2, old_line);
	gnl_strlcat(*line, buffer, total_len + 1);
}

static char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len >= s_len - start)
		len = s_len - start;
	res = ft_malloc((len + 1) * sizeof(char),(t_mem_manage_params){NULL, 2, NULL, 0});
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char *gnl_line(char **line, ssize_t pos)
{
	size_t	rest_len;
	char	*res;
	char	*temp;
	
	if (pos == -1)
	{
		temp = *line;
		*line = NULL;
		return temp;
	}
	res = gnl_substr(*line, 0, pos + 1);
	if (!res)
	{
		*line = NULL;
		return NULL;
	}
	rest_len = gnl_strlen(*line);
	temp = *line;
	*line = gnl_substr(*line, pos + 1,  rest_len);
	if (!(*line))
		return *line;
	ft_free_node(2, temp);
	return res;
}

static char *gnl_helper(int fd, char **res)
{
    ssize_t	read_count;
	ssize_t	nl_pos;
    char	buffer[BUFFER_SIZE + 1];
	
    read_count = read(fd, buffer, BUFFER_SIZE);
    if (read_count == -1)
    {
        *res = NULL;
        return (ft_free(0, TRUE), *res);
    }
    while (read_count >= 0 || *res)
    {
		buffer[read_count] = 0;
        if (read_count)
            gnl_strjoin(res, buffer);
		nl_pos = find_new_line(*res);
        if (nl_pos >= 0)
			return (gnl_line(res, nl_pos));
		if (!read_count && nl_pos == -1)
			return (gnl_line(res, nl_pos));
		read_count = read (fd, buffer, BUFFER_SIZE);
    }
	return (NULL);
}

char *get_next_line(int fd)
{
    static char *keeper;
	char	*res;

    if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	res = gnl_helper(fd, &keeper);
	// mem_move((t_mem_manage_params){NULL, 2, res, 1});
	// ft_print_memory();
	return res;
}
