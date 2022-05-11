/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:18:47 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 11:15:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"
#include "test.h"
#include "tracing.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parsing(&scene, argc, argv);
	print_scene(&scene);
	drive_ray_tracing(&scene);
	mlx_loop(scene.mlx_info.mlx);
	// while (1);
	return (0);
}