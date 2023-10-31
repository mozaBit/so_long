/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 02:31:56 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/26 20:22:11 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
	** Testing ...
	int
	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
*/
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

/*
	** Testing ...
	int
	mlx_string_put(void *mlx_ptr, void *win_ptr,
									int x, int y, int color, char *string);
*/
void	draw_phrase(t_data data, t_coordinate cds, int colors, char *message)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, cds.x, cds.y, colors, message);
}

/*
	** Testing ...
	int
	mlx_clear_window(void *mlx_ptr, void *win_ptr);
*/
void	clear_window(t_data data)
{
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
}

/*
	** Testing ...
	int
	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
*/
void	destroy_window(t_data data)
{
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
}
