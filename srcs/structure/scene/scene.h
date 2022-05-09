/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:01:34 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 21:17:16 by mypark           ###   ########.fr       */
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
void	clear_scene(t_scene *scene);

#endif