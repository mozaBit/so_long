/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:06:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/12 23:10:56 by bmetehri         ###   ########.fr       */
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
		map = ft_strjoin(map, line);
		free(line);
		game->map.rows++;
	}
	close(fd);
	check_map_errors(map, game);
	game->map.map_strs = ft_split(map, '\n');
	game->map_allocated = true;
	free(map);
}
