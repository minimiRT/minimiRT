/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:01:34 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:23:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "canvas.h"
# include "camera.h"
# include "ambient.h"
# include "world.h"
# include "mlx_info.h"

typedef struct s_scene	t_scene;

struct s_scene
{
	t_camera	camera;
	t_canvas	canvas;
	t_world		world;
	t_ambient	ambient;
	t_mlx_info	mlx_info;
};

void	init_scene(t_scene *scene);
void	clear_scene(t_scene *scene);

#endif