/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 15:54:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "libft.h"
#include "utils.h"

void	add_new_plane(t_objects **objects, char **splited)
{
	t_object	*object;
	t_plane		*plane;

	ft_assert(splited[1] != NULL, "Error: invalid format of plane\n");
	ft_assert(splited[2] != NULL, "Error: invalid format of plane\n");
	ft_assert(splited[3] != NULL, "Error: invalid format of plane\n");
	plane = malloc(sizeof(t_plane));
	object = malloc(sizeof(t_object));
	ft_assert(plane != FT_NULL, "Error: malloc failed in add_new_plane");
	ft_assert(object != FT_NULL, "Error: malloc failed in add_new_plane");
	plane->center = parse_vec3(splited[1]);
	plane->normal = get_unit_vec3(parse_vec3(splited[2]));
	object->albedo = parse_color(splited[3]);
	object->element = plane;
	object->type = PLANE;
	ft_lstadd_back(objects, ft_lstnew(object));
}
