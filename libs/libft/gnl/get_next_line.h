/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:55:54 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 20:47:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
	int					fd;
}				t_gnl_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_realloc(char *original, int desired);
int		check_nl(char *buf);
int		append_buf(char **m_buf, char *r_buf, int r_state);
int		make_line(char **m_buf, char *remains);
int		read_fd(int fd, char **m_buf, char *r_buf, char *remains);
char	*get_remains(int fd, t_gnl_list *head);
void	free_list(int fd, t_gnl_list *prev, t_gnl_list *curr);
t_gnl_list	*new_node(int fd);

#endif
