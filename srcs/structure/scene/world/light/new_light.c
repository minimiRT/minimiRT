/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 11:02:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "constant.h"
#include "utils.h"
#include <stdlib.h>

t_light	*new_light(t_point3 origin, t_color3 color, double bright_ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	ft_assert(light != FT_NULL, "Assert: malloc failed in new_light\n");
	light->origin = origin;
	light->color = color;
	light->bright_ratio = bright_ratio;
	return (light);
}