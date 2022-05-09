/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:03:53 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 13:39:08 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# define CANVAS_HEIGHT	720
# define CANVAS_WIDTH	1280
typedef struct s_canvas t_canvas;

struct  s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

void		free_canvas(t_canvas *canvas);
t_canvas	*new_canvas(int width, int height);

#endif