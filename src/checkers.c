/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:09:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 00:35:29 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_rows(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->map.rows)
	{
		if (game->map.map_strs[idx][0] != BOUNDARY)
			error_print("Error: \
			 Invalid Map: A boundary is missing in the first column", game);
		if (game->map.map_strs[idx][game->map.columns - 1] != BOUNDARY)
			error_print("Error: \
			 Invalid Map: A boundary is missing in the last column", game);
		idx++;
	}
}

void	check_columns(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->map.rows)
	{
		if (game->map.map_strs[0][idx] != BOUNDARY)
			error_print("Error: \
			 Invalid Map: A boundary is missing in the first row", game);
		if (game->map.map_strs[game->map.rows - 1][idx] != BOUNDARY)
			error_print("Error: \
			 Invalid Map: A boundary is missing in the last row", game);
		idx++;
	}
}

void	count_params(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.rows)
	{
		i = 0;
		while (i < game->map.columns)
		{
			if (!ft_strchr("10PEC", game->map.map_strs[j][i]))
				error_print("Error: Invalid Map: Invalid Map Indicator", game);
			if (game->map.map_strs[j][i] == CHARACTER)
			{
				game->map.characters++;
				game->map.character.x = i;
				game->map.character.y = j;
			}
			if (game->map.map_strs[j][i] == COLLECTABLE)
				game->map.collectables++;
			if (game->map.map_strs[j][i] == M_EXIT)
				game->map.exit++;
			i++;
		}
		j++;
	}
}

void	verify_params(t_game *game)
{
	if (game->map.collectables == 0)
		error_print("Error: Inavlid Map: Map must contains at least one collectable", game);
	if (game->map.exit == 0)
		error_print("Error: Inavlid Map: Map must contains an exit", game);
	if (game->map.characters != 1)
		error_print("Error: Inavlid Map: Map must contains at most a player", game);

}
