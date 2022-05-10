/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 20:27:33 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "libft.h"
#include "utils.h"

void	add_new_sphere(t_objects **objects, char **splited)
{
	t_object	*object;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	object = malloc(sizeof(t_object));
	ft_assert(sphere != FT_NULL, "Assert: malloc failed in add_new_sphere");
	ft_assert(object != FT_NULL, "Assert: malloc failed in add_new_sphere");
	sphere->center = parse_vec3(splited[1]);
	sphere->radius = (parse_positive_double(splited[2]) / 2);
	object->albedo = parse_color(splited[3]);
	object->element = sphere;
	object->type = SPHERE;
	ft_lstadd_back(objects, ft_lstnew(object));
}