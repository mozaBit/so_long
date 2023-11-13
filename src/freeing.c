/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:46 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 18:14:24 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void end_imgs(t_game *game);
void free_maps(t_game *game);
void	free_stuffs(t_game *game);

void	free_stuffs(t_game *game)
{
	end_imgs(game);
	free_maps(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game->win_ptr);
	free(game);

}

void end_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->boundary.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->ground.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->c_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->c_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->c_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->c_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->o_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->c_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectable.xpm_ptr);
}

void free_maps(t_game *game)
{
	int c;

	c = 0;
	while (c < game->map.rows)
		free(game->map.map_strs[c++]);
	free(game->map.map_strs);
}
