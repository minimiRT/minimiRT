/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:28:49 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:46:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	append_buf(char **m_buf, char *r_buf, int r_len)
{
	int	len_m;
	int	len_r;

	r_buf[r_len] = '\0';
	len_m = ft_strlen(*m_buf);
	len_r = ft_strlen(r_buf);
	*m_buf = ft_realloc(*m_buf, len_m + len_r + 1);
	if (*m_buf == NULL)
		return (0);
	ft_strlcat(*m_buf, r_buf, -1);
	return (1);
}

char	*get_remains(int fd, t_gnl_list *head)
{
	t_gnl_list	*curr;
	t_gnl_list	*prev;

	curr = head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr->content);
		prev = curr;
		curr = curr->next;
	}
	prev->next = new_node(fd);
	if (prev->next == NULL)
		return (NULL);
	return (prev->next->content);
}

int	read_fd(int fd, char **m_buf, char *r_buf, char *remains)
{
	int	r_len;

	remains[0] = '\0';
	r_buf[0] = '\0';
	while (1)
	{
		if (check_nl(*m_buf) != -1)
		{
			ft_strlcat(remains, *m_buf + check_nl(*m_buf) + 1, -1);
			*m_buf = ft_realloc(*m_buf, check_nl(*m_buf) + 2);
			if (*m_buf == NULL)
				return (-1);
			return (-2);
		}
		else
		{
			r_len = read(fd, r_buf, BUFFER_SIZE);
			if (r_len == 0 && ft_strlen(*m_buf))
				return (-2);
			if (r_len <= 0)
				return (fd);
			if (append_buf(m_buf, r_buf, r_len) == 0)
				return (-1);
		}
	}
}

void	free_list(int fd, t_gnl_list *prev, t_gnl_list *curr)
{
	t_gnl_list	*node;

	while (fd >= 0 && curr)
	{
		if (curr->fd == fd)
		{
			prev->next = curr->next;
			free(curr->content);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	while (curr)
	{
		node = curr;
		curr = curr->next;
		free(node->content);
		free(node);
	}
	prev->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_gnl_list	head = {NULL, NULL, -1};
	char				*remains;
	char				r_buf[BUFFER_SIZE + 1];
	char				*m_buf;
	int					fd_state;

	if (fd < 0)
		return (NULL);
	remains = get_remains(fd, &head);
	m_buf = malloc(sizeof(char) * ft_strlen(remains) + 1);
	if (remains == NULL || m_buf == NULL)
	{
		free_list(-1, &head, head.next);
		return (NULL);
	}
	m_buf[0] = '\0';
	ft_strlcat(m_buf, remains, -1);
	fd_state = read_fd(fd, &m_buf, r_buf, remains);
	if (fd_state > -2)
	{
		free_list(fd_state, &head, head.next);
		free(m_buf);
		return (NULL);
	}
	return (m_buf);
}
