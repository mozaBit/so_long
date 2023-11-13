/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:02:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 18:46:00 by bmetehri         ###   ########.fr       */
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
	void	*mlx_ptr;

	mlx_ptr = game->mlx_ptr;
	game->boundary = init_new_sprite(mlx_ptr, BOUNDARY_XPM, game);
	game->ground = init_new_sprite(mlx_ptr, GROUND_XPM, game);
	game->collectable = init_new_sprite(mlx_ptr, COLLECTABLE_XPM, game);
	game->c_front = init_new_sprite(mlx_ptr, P_FRONT_XPM, game);
	game->c_back = init_new_sprite(mlx_ptr, P_BACK_XPM, game);
	game->c_right = init_new_sprite(mlx_ptr, P_RIGHT_XPM, game);
	game->c_left = init_new_sprite(mlx_ptr, P_LEFT_XPM, game);
	game->o_exit = init_new_sprite(mlx_ptr, O_EXIT, game);
	game->c_exit = init_new_sprite(mlx_ptr, C_EXIT, game);
}

t_image	init_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	spritesheet;

	spritesheet.xpm_ptr = mlx_xpm_file_to_image(mlx, \
	path, &spritesheet.x, &spritesheet.y);
	if (!spritesheet.xpm_ptr)
		error_print("Error: Failed to create a spritesheet", game);
	return (spritesheet);
}
