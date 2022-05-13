/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:37:15 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 20:37:16 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "utils.h"

static int	key_press(int key, void *param)
{
	(void)param;
	if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

static int	exit_when_closing_win(void *param)
{
	(void)param;
	exit(0);
}

void	control_exit(t_mlx_info *mlx_info)
{
	int	win_button_esc;

	win_button_esc = 17;
	mlx_hook(mlx_info->win, KEYPRESS, 0, key_press, mlx_info);
	mlx_hook(mlx_info->win, win_button_esc, 0, exit_when_closing_win, mlx_info);
}
