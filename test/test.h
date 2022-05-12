/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:10:24 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 13:39:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include "scene.h"

void	print_vec3(t_vec3 *vec);
void	print_scene(t_scene *scene);
void	write_color(t_color3 *pixel_color);
void	print_sphere(t_sphere *sphere);

#endif