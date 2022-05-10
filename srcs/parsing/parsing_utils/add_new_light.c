/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 20:26:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "utils.h"

void	add_new_light(t_lights **lights, char **splited)
{
	t_light		*light;

	light = malloc(sizeof(t_light));
	ft_assert(light != FT_NULL, "Assert: malloc faild in add_new_light\n");
	light->origin = parse_vec3(splited[1]);
	light->bright_ratio = parse_ratio(splited[2]);
	light->color = parse_color(splited[3]);
	ft_lstadd_back(lights, ft_lstnew(light));
}