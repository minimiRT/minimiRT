/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:06:29 by mypark            #+#    #+#             */
/*   Updated: 2022/05/15 14:51:52 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3	t_vec3;
typedef t_vec3			t_point3;
typedef t_vec3			t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

void	copy_vec3(t_vec3 src, t_vec3 *dest);
t_vec3	init_vec3(double x, double y, double z);
t_vec3	*dup_vec3(t_vec3 vec);
t_vec3	*new_vec3(double x, double y, double z);
t_vec3	add_vec3(t_vec3 first, t_vec3 second);
t_vec3	plus_vec3(t_vec3 vec, double x, double y, double z);
t_vec3	sub_vec3(t_vec3 first, t_vec3 second);
t_vec3	minus_vec3(t_vec3 vec, double x, double y, double z);
t_vec3	mul_vec3(t_vec3 first, t_vec3 second);
t_vec3	mul_vec3_t(t_vec3 vec, double t);
t_vec3	div_vec3(t_vec3 first, t_vec3 second);
t_vec3	div_vec3_t(t_vec3 vec, double t);
double	dot_vec3(t_vec3 first, t_vec3 second);
t_vec3	cross_vec3(t_vec3 first, t_vec3 second);
t_vec3	get_unit_vec3(t_vec3 vec);
t_vec3	get_min_between_vec3(t_vec3 first, t_vec3 second);
double	get_vec3_len(t_vec3 vec);
double	get_vec3_len_square(t_vec3 vec);
int		is_same_vec3(t_vec3 a, t_vec3 b);

#endif