/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:06:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 13:39:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include "hit_cylinder.h"
#include <math.h>

t_bool	hit_cylinder(t_object *object, t_trace *tracing)
{
	t_cylinder	*cylinder;
	t_vec3		vec_co;

	cylinder = object->element;
	vec_co = sub_vec3(tracing->ray.origin, cylinder->center);
	if (hit_cylinder_side(cylinder, tracing, vec_co) == TRUE)
	{
		tracing->record.albedo = object->albedo;
		return (TRUE);
	}
	if (hit_cylinder_circle(cylinder, tracing, vec_co) == TRUE)
	{
		tracing->record.albedo = object->albedo;
		return (TRUE);
	}
	return (FALSE);
}
