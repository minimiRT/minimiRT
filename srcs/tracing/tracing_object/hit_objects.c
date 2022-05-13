/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:31 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 10:50:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing_object.h"

static t_bool	hit_object(t_object *object, t_trace *tracing)
{
	t_bool	is_hitting;

	is_hitting = FALSE;
	if (object->type == SPHERE)
		is_hitting = hit_sphere(object, tracing);
	if (object->type == PLANE)
		is_hitting = hit_plane(object, tracing);
	if (object->type == CYLINDER)
		is_hitting = hit_cylinder(object, tracing);
	return (is_hitting);
}

t_bool	hit_objects(t_objects *objects, t_trace *tracing)
{
	t_bool			is_hitting;

	tracing->record = init_hit_record();
	is_hitting = FALSE;
	while (objects)
	{
		if (hit_object(objects->content, tracing))
		{
			is_hitting = TRUE;
			tracing->record.max = tracing->record.distance_from_ray_origin;
		}
		objects = objects->next;
	}
	return (is_hitting);
}
