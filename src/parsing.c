/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:06:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 20:52:48 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
	check args : functions checks input args if they are compatible
	Problem : Still runnning the ...ber file and not just .ber files
*/
void	ft_check_args(int ac, char **av, t_game *game)
{
	int	l;

	game->map_allocated = false;
	if (ac != 2 || !av[1] || !av[1][0])
		error_print("Error: Invalid Args", game);
	l = ft_strlen(av[1]);
	if (!ft_strnstr(av[1], ".ber", l) || l <= 4
		|| ft_strlen(ft_strnstr(av[1], ".ber", l)) != 4)
		error_print("Error: No .ber in Args", game);
	if (open(av[1], O_RDONLY) == -1)
		error_print("Error: Cannot read file", game);
}

void	init_map(char *av, t_game *game)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_print("Error: Cannot open file", game);
	map = ft_strdup("");
	game->map.rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = ft_strappend(&map, line);
		free(line);
		game->map.rows++;
	}
	close(fd);
	check_map_errors(map, game);
	game->map.map_strs = ft_split(map, '\n');
	game->map_allocated = true;
	free(map);
}

void	vars_init(t_game *game)
{
	game->map.collectables = 0;
	game->map.characters = 0;
	game->map.exit = 0;
	game->map.columns = ft_strlen(game->map.map_strs[0]) - 1;
	game->movements = 0;
	game->character_sheet = FRONT;
}

void	check_map(t_game *game)
{
	check_rows(game);
	check_columns(game);
	count_params(game);
	verify_params(game);
}

int	is_s(t_game *game, int target_i, int target_j)
{
	int	i;
	int	j;

	i = target_i - 1;
	while (i <= target_i + 1)
	{
		j = target_j - 1;
		while (j <= target_j + 1)
		{
			if (j >= 0 && j < game->map.rows && i >= 0 && i < game->map.columns)
			{
				if (game->map.map_strs[j][i] != BOUNDARY
					&& !(i == target_i && j == target_j))
					return (0);
			}
			else
			{
				return (error_print("Error\n Item surronded", game), 1);
			}
			j++;
		}
		i++;
	}
	return (error_print("Error\n Item surronded", game), 1);
}
