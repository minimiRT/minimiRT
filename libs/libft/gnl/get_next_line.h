/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:55:54 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 13:26:43 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	int				fd;
}				t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_realloc(char *original, int desired);
int		check_nl(char *buf);
int		append_buf(char **m_buf, char *r_buf, int r_state);
int		make_line(char **m_buf, char *remains);
int		read_fd(int fd, char **m_buf, char *r_buf, char *remains);
char	*get_remains(int fd, t_list *head);
void	free_list(int fd, t_list *prev, t_list *curr);
t_list	*new_node(int fd);

#endif
