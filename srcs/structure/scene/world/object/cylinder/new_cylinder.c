/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:08:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "constant.h"
#include "utils.h"
#include <stdlib.h>

t_cylinder	*new_cylinder(\
	t_point3 center, \
	t_vec3 orientation, \
	double radius, \
	double height\
)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	ft_assert(cylinder != FT_NULL, "Assert: malloc failed in new_cylinder\n");
	cylinder->center = center;
	cylinder->orientation = orientation;
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}
