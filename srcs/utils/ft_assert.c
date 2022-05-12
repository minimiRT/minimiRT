/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:37:28 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 10:50:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enum.h"
#include "libft.h"

void	ft_assert(t_bool condition, char *msg)
{
	if (condition)
		return ;
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(1);
}