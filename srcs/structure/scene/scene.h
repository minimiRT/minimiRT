/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:01:34 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 10:41:49 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "canvas.h"
# include "camera.h"
# include "ambient.h"
# include "world.h"

typedef struct s_scene	t_scene;

struct s_scene
{
	t_camera	camera;
	t_canvas	canvas;
	t_world		world;
	t_ambient	ambient;
};

void	init_scene(t_scene *scene);
void	reset_scene(t_scene *scene);

#endif