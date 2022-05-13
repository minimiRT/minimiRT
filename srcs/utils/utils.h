/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:55:39 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 15:15:56 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "enum.h"
# include "mlx_info.h"

# define KEYPRESS 2
# define KEY_ESCAPE 53

void	ft_assert(t_bool condition, char *msg);
void	control_exit(t_mlx_info *mlx_info);

#endif