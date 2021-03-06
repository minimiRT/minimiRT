/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:03:53 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:10:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# define CANVAS_HEIGHT	800
# define CANVAS_WIDTH	800

typedef struct s_canvas	t_canvas;

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

#endif