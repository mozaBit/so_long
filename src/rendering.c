/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:31:03 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 04:30:34 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	render_everything(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.rows)
	{
		i = 0;
		while (i < game->map.columns)
		{
			get_spritesheet(game, i, j);
			i++;
		}
		j++;
	}
	print_movements(game);
	return (0);
}

void	render_spritesheet(t_game *game, t_image img, int j, int i)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img.xpm_ptr, i * img.x, j * img.y);
}

void	get_spritesheet(t_game *game, int i, int j)
{
	char	param;

	param = game->map.map_strs[j][i];
	if (param == BOUNDARY)
		render_spritesheet(game, game->boundary, j, i);
	if (param == GROUND)
		render_spritesheet(game, game->ground, j, i);
	if (param == COLLECTABLE)
		render_spritesheet(game, game->collectable, j, i);
	if (param == CHARACTER)
		render_character(game, j, i);
	if (param == M_EXIT)
	{
		if (game->map.collectables == 0)
			render_spritesheet(game, game->o_exit, j, i);
		else
			render_spritesheet(game, game->c_exit, j, i);
	}
}

void	render_character(t_game *game, int j, int i)
{
	if (game->character_sheet == FRONT)
		render_spritesheet(game, game->c_front, j, i);
	if (game->character_sheet == BACK)
		render_spritesheet(game, game->c_back, j, i);
	if (game->character_sheet == RIGHT)
		render_spritesheet(game, game->c_right, j, i);
	if (game->character_sheet == LEFT)
		render_spritesheet(game, game->c_left, j, i);
}

void	print_movements(t_game *game)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->movements);
	str = ft_strjoin("Movements: ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, str);
	free(moves);
	free(str);
}
