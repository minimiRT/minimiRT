/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:32:18 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:10:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_info.h"
#include "canvas.h"
#include "utils.h"
#include "constant.h"

void	init_mlx_info(t_mlx_info *mlx_info)
{
	mlx_info->mlx = mlx_init();
	ft_assert(mlx_info->mlx != FT_NULL, "Assert: mlx_init error\n");
	mlx_info->win = mlx_new_window(mlx_info->mlx, \
									CANVAS_WIDTH, CANVAS_HEIGHT, "minimiRT");
	ft_assert(mlx_info->win != FT_NULL, "Assert: mlx_new_window error\n");
	mlx_info->img = mlx_new_image(mlx_info->mlx, CANVAS_WIDTH, CANVAS_HEIGHT);
	ft_assert(mlx_info->img != FT_NULL, "Assert: mlx_new_image error\n");
	mlx_info->data_addr = mlx_get_data_addr(mlx_info->img, \
			&(mlx_info->bpp), &(mlx_info->size_line), &(mlx_info->endian));
	return ;
}
