/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:18:47 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 13:31:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"
#include "test.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parsing(&scene, argc, argv);
	print_scene(&scene);
	// while (1);
}