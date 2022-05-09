/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:38 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 14:07:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAMERA_H
# define CAMERA_H
# include "vec3.h"
# include "canvas.h"
# define VIEWPORT_HEIGHT	2.0
# define FOCAL_LEN			1.0

typedef struct s_camera t_camera;

struct s_camera
{
	t_point3	origin;
	double		viewport_height;
	double		viewport_width;
	t_vec3		horizontal_len;
	t_vec3		vertical_len;
	t_vec3		focal_len;
	t_point3	left_bottom;
};

t_camera	*new_camera(t_canvas *canvas, t_point3 *origin);
void		free_camera(t_camera *camera);

#endif