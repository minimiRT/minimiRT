/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:28:56 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 13:26:01 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	if (s == NULL)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
	{
		return (len_src + dstsize);
	}
	i = len_dst;
	while (i < dstsize - 1 && src[i - len_dst])
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

char	*ft_realloc(char *original, int desired)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * desired);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	ft_strlcat(tmp, original, desired);
	free(original);
	return (tmp);
}

int	check_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_list	*new_node(int fd)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (node->content == NULL)
		return (NULL);
	node->next = NULL;
	node->content[0] = '\0';
	node->fd = fd;
	return (node);
}
