/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 20:58:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "libft.h"
#include "utils.h"

void	add_new_cylinder(t_objects *objects, char **splited)
{
	t_object	*object;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	object = malloc(sizeof(t_object));
	ft_assert(cylinder != FT_NULL, "Assert: malloc failed in add_new_cylinder");
	ft_assert(object != FT_NULL, "Assert: malloc failed in add_new_cylinder");
	cylinder->center = parse_vec3(splited[1]);
	cylinder->orientation = get_unit_vec3(parse_vec3(splited[2]));
	cylinder->radius = (parse_double(splited[3])) / 2;
	cylinder->height = parse_double(splited[4]);
	object->albedo = parse_vec3(splited[5]);
	object->element = cylinder;
	object->type = CYLINDER;
	ft_lstadd_back(&objects, ft_lstnew(object)); //init scene에서 objects null 초기화
}