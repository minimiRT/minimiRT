/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:58:38 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 14:02:41 by mypark           ###   ########.fr       */
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
	t_vec3		horizontal_vec;
	t_vec3		vertical_vec;
	t_vec3		focal_vec;
	t_point3	left_bottom;
};

#endif