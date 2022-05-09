/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 21:17:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	init_scene(t_scene *scene)
{
	scene->world.lights = NULL;
	scene->world.objects = NULL;
	return ;
}