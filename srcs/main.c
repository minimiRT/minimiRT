/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:18:47 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 21:24:09 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parsing(&scene, argc, argv);
}