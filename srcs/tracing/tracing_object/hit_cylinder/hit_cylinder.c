/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:06:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 13:52:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include "hit_cylinder.h"
#include <math.h>

t_bool	hit_cylinder(t_object *object, t_trace *tracing)
{
	t_cylinder	*cylinder;
	t_vec3		vec_co;
	t_bool		hit_side;
	t_bool		hit_circle;

	cylinder = object->element;
	vec_co = sub_vec3(tracing->ray.origin, cylinder->center);
	hit_circle = hit_cylinder_circle(cylinder, tracing, vec_co);
	hit_side = hit_cylinder_side(cylinder, tracing, vec_co);
	if (hit_circle == FALSE && hit_side == FALSE)
		return (FALSE);
	tracing->record.albedo = object->albedo;
	return (TRUE);
}
