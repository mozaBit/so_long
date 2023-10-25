/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 02:31:56 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/25 03:21:05 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_square(t_data data, int x, int y, int colors)
{
	int	idx;
	int	jdx;

	idx = -1;
	while (idx++ < 100)
	{
		jdx = -1;
		while (jdx++ < 100)
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x + idx, y + jdx, colors);
	}
}
