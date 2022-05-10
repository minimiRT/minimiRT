/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:05:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*new_light(t_point3 origin, t_color3 color, double bright_ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->origin = origin;
	light->color = color;
	light->bright_ratio = bright_ratio;
}