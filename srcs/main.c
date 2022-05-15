/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:18:47 by mypark            #+#    #+#             */
/*   Updated: 2022/05/15 13:32:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"
#include "tracing.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parsing(&scene, argc, argv);
	init_mlx_info(&scene.mlx_info);
	drive_ray_tracing(&scene);
	control_exit(&(scene.mlx_info));
	mlx_loop(scene.mlx_info.mlx);
	return (0);
}
