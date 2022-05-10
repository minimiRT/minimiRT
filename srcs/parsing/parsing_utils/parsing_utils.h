/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:28 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 20:25:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H
# include "vec3.h"
# include "scene.h"

t_vec3	parse_vec3(char *str);
t_vec3	parse_color(char *str);
double	parse_double(char *str);
double	parse_ratio(char *str);
double	parse_fov(char *str);
double	parse_positive_double(char *str);
char	**ft_strsep(char const *s, char c);
void	add_new_cylinder(t_objects **objects, char **splited);
void	add_new_light(t_lights **lights, char **splited);
void	add_new_plane(t_objects **objects, char **splited);
void	add_new_sphere(t_objects **objects, char **splited);
void	set_ambient(t_ambient *ambient, char **splited);
void	set_camera(t_camera *camera, t_canvas *canvas, char **splited);

# endif
