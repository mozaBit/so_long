/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:02:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 02:12:51 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initilize_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		error_print("Error: Failed To receive mlx pointer", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * S_WIDTH, game->map.rows * S_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		error_print("Error: Failed to Create Window", game);
	}
}

void	initialize_sheets(t_game *game)
{

}
