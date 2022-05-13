/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 15:54:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "libft.h"
#include "utils.h"

void	add_new_cylinder(t_objects **objects, char **splited)
{
	t_object	*object;
	t_cylinder	*cylinder;

	ft_assert(splited[1] != NULL, "Error: invalid format of cylinder\n");
	ft_assert(splited[2] != NULL, "Error: invalid format of cylinder\n");
	ft_assert(splited[3] != NULL, "Error: invalid format of cylinder\n");
	ft_assert(splited[4] != NULL, "Error: invalid format of cylinder\n");
	ft_assert(splited[5] != NULL, "Error: invalid format of cylinder\n");
	cylinder = malloc(sizeof(t_cylinder));
	object = malloc(sizeof(t_object));
	ft_assert(cylinder != FT_NULL, "Error: malloc failed in add_new_cylinder");
	ft_assert(object != FT_NULL, "Error: malloc failed in add_new_cylinder");
	cylinder->center = parse_vec3(splited[1]);
	cylinder->orientation = get_unit_vec3(parse_vec3(splited[2]));
	cylinder->radius = (parse_positive_double(splited[3])) / 2;
	cylinder->height = parse_positive_double(splited[4]);
	object->albedo = parse_color(splited[5]);
	object->element = cylinder;
	object->type = CYLINDER;
	ft_lstadd_back(objects, ft_lstnew(object));
}
