/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:01:34 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 09:33:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H

typedef struct s_mlx t_mlx;

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
};

#endif
