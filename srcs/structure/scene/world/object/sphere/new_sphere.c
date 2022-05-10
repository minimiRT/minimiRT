/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 11:03:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "constant.h"
#include "utils.h"
#include <stdlib.h>

t_sphere	*new_sphere(t_point3 center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	ft_assert(sphere != FT_NULL, "Assert: malloc failed in new_sphere\n");
	sphere->center = center;
	sphere->radius = radius;
	sphere->radius_square = radius * radius;
	return (sphere);
}