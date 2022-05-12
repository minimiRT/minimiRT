/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:58 by mgo               #+#    #+#             */
/*   Updated: 2022/05/12 17:27:59 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACING_H
# define TRACING_H

# include "scene.h"
# include "enum.h"
# include "pixel.h"
# include "mlx.h"

void		drive_ray_tracing(t_scene *scene);
t_color3	get_color_from_phong_lighting(t_scene *scene, t_trace *tracing);
void		draw_pixel(t_scene *scene, t_pixel *pixel);

t_bool		hit_objects(t_objects *objects, t_trace *tracing);
t_bool		hit_sphere(t_object *object, t_trace *tracing);
t_bool		hit_plane(t_object *object, t_trace *tracing);

#endif
