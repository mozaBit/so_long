/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:32:15 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 05:04:41 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_move(t_game *game, int n_j, int n_i, int sprite);

int		handle_input(int key, t_game *game)
{
	if (key == KEY_SW || key == KEY_CW || key == KEY_UP)
		player_move(game, game->map.character.y - 1, game->map.character.x, BACK);
	if (key == KEY_SS || key == KEY_CS || key == KEY_DOWN)
		player_move(game, game->map.character.y + 1, game->map.character.x, FRONT);
	if (key == KEY_SD || key == KEY_CD || key == KEY_RIGHT)
		player_move(game, game->map.character.y, game->map.character.x + 1, RIGHT);
	if (key == KEY_SA || key == KEY_CA || key == KEY_LEFT)
		player_move(game, game->map.character.y, game->map.character.x - 1, LEFT);
}

void	player_move(t_game *game, int n_j, int n_i, int sprite)
{
	int	l_i;
	int	l_j;

	game->character_sheet = sprite;
	l_i = game->map.character.x;
	l_j = game->map.character.y;
	if (game->map.map_strs[n_j][n_i] == M_EXIT && game->map.collectables == 0)
		victory(game);
	if (game->map.map_strs[n_j][n_i] == GROUND
		|| game->map.map_strs[n_j][n_i] == COLLECTABLE)
	{
		game->map.map_strs[l_j][l_i] = GROUND;
		if (game->map.map_strs[n_j][n_i] == COLLECTABLE)
			game->map.collectables--;
		game->map.character.x = n_i;
		game->map.character.y = n_j;
		game->map.map_strs[n_j][n_i] = CHARACTER;
		game->movements++;
		render_everything(game);
	}
}
