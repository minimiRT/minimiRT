/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:58 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 09:44:39 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACING_H
# define TRACING_H

# include "scene.h"
# include "enum.h"
# include "pixel.h"
# include "mlx.h"

void		drive_ray_tracing(t_scene *scene);
t_bool		hit_objects(t_objects *objects, t_trace *tracing);
t_color3	get_color_from_phong_lighting(t_scene *scene, t_trace *tracing);
void		draw_pixel(t_scene *scene, t_pixel *pixel);

#endif
