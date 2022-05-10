/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 21:23:57 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"
#include "utils.h"
#include "parsing_utils.h"
#include <fcntl.h>

static void	parse_line(t_scene *scene, char *line)
{
	char **splited;

	if (line[0] == '\0')
		return ;
	splited = ft_split(line, ' ');
	if (ft_strncmp(splited[0], "A", -1) == 0)
		set_ambient(&scene->ambient, splited);
	else if (ft_strncmp(splited[0], "C", -1) == 0)
		set_camera(&scene->camera, splited);
	else if (ft_strncmp(splited[0], "L", -1) == 0)
		add_new_light(scene->world.lights, splited);
	else if (ft_strncmp(splited[0], "sp", -1) == 0)
		add_new_sphere(scene->world.objects, splited);
	else if (ft_strncmp(splited[0], "pl", -1) == 0)
		add_new_plane(scene->world.objects, splited);
	else if (ft_strncmp(splited[0], "cy", -1) == 0)
		add_new_cylinder(scene->world.objects, splited);
	ft_splitfree(splited);
}

void	parsing(t_scene *scene, int argc, char **argv)
{
	char	*dot;
	char	*line;
	int		fd;

	ft_assert(argc == 2, "Error\n");
	dot = ft_strrchr(argv[1], '.');
	ft_assert(ft_strncmp(".rt", dot, -1) == 0, "Error\n");
	fd = open(argv[1], O_RDONLY);
	ft_assert(fd != -1, "Error\n"); // error msg?
	line = get_next_line(fd);
	while (line)
	{
		parse_line(scene, line);
		free(line);
		line = get_next_line(fd);
	}
}