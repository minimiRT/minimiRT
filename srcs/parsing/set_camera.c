/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 16:32:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"

void	set_camera(t_camera *camera, char **splited)
{
	copy_vec3(parse_vec3(splited[1]), &camera->origin);
	//?
}