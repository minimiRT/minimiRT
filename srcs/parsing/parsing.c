/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/15 15:53:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"
#include "utils.h"
#include "constant.h"
#include "parsing_utils.h"
#include <fcntl.h>

static void	parse_line(t_scene *scene, char *line, int	*basic_component)
{
	char	**splited;

	splited = ft_split(line, ' ');
	if (ft_strncmp(splited[0], "A", -1) == 0)
	{
		set_ambient(&scene->ambient, splited);
		basic_component[0]++;
	}
	else if (ft_strncmp(splited[0], "C", -1) == 0)
	{
		set_camera(&scene->camera, &scene->canvas, splited);
		basic_component[1]++;
	}
	else if (ft_strncmp(splited[0], "L", -1) == 0)
		add_new_light(&scene->world.lights, splited);
	else if (ft_strncmp(splited[0], "sp", -1) == 0)
		add_new_sphere(&scene->world.objects, splited);
	else if (ft_strncmp(splited[0], "pl", -1) == 0)
		add_new_plane(&scene->world.objects, splited);
	else if (ft_strncmp(splited[0], "cy", -1) == 0)
		add_new_cylinder(&scene->world.objects, splited);
	else
		ft_assert(FALSE, "Error: invalid type of component\n");
	ft_splitfree(splited);
}

static void	set_canvas(t_canvas *canvas)
{
	canvas->width = CANVAS_WIDTH;
	canvas->height = CANVAS_HEIGHT;
	canvas->aspect_ratio = (double)CANVAS_WIDTH / (double)CANVAS_HEIGHT;
}

void	parsing(t_scene *scene, int argc, char **argv)
{
	char	*dot;
	char	*line;
	int		fd;
	int		basic_component[2];

	basic_component[0] = 0;
	basic_component[1] = 0;
	ft_assert(argc == 2, "Error: Bad arguments\n");
	dot = ft_strrchr(argv[1], '.');
	ft_assert(dot != FT_NULL, "Error: invalid file extension\n");
	ft_assert(ft_strncmp(".rt", dot, -1) == 0, \
							"Error: invalid file extension\n");
	fd = open(argv[1], O_RDONLY);
	ft_assert(fd != -1, "Error: file open failed\n");
	set_canvas(&scene->canvas);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\0')
			parse_line(scene, line, basic_component);
		free(line);
		line = get_next_line(fd);
	}
	ft_assert(basic_component[0] == 1, "Error: invalid counts of Ambient\n");
	ft_assert(basic_component[1] == 1, "Error: invalid counts of Camera\n");
}
