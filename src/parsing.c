/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:06:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/01 21:23:42 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
	check args : functions checks input args if they are compatible
	Problem : Still runnning the ...ber file and not just .ber files
*/
void	check_args(int ac, char **av)
{
	int	l;

	if (ac != 2 || !av[1] || !av[1][0])
		return (ft_printf("Error: Invalid Args\n"), exit(1));
	l = ft_strlen(av[1]);
	if (!ft_strnstr(av[1], ".ber", l) || l <= 4
		|| ft_strlen(ft_strnstr(av[1], ".ber", l)) != 4)
		return (ft_printf("Error: No .ber in Args\n"), exit(1));
	if (open(av[1], O_RDONLY) == -1)
		return (perror("Error"), exit(1));
}

void	create_map(t_data data, char *filename)
{
	int		fd;
	char	*my_map_str;
	t_map	my_map;

	(void) data;
	fd = open(filename, O_RDONLY);
	my_map_str = get_my_map_str(fd);
	ft_printf("%s\n", my_map);
	// my_map = get_my_map_struct(my_map_str);
}

char	*get_my_map_str(int fd)
{
	char	*tmp;
	char	*buf;
	int		all_read;

	all_read = 0;
	buf = malloc(sizeof(char) * 1);
	buf[0] = '\0';
	while (!all_read)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			all_read = 1;
			continue ;
		}
		buf = ft_strjoin(buf, tmp);
	}
	return (buf);
}

t_map	get_my_map_sturct(char *my_map_str)
{
	t_map		*my_map;
	t_player	*player;

	my_map = malloc(sizeof(t_map));
	player = get_player(my_map_str);
	player->height = 40;
	player->width = 40;
	my_map->player = *player;
	my_map->boundaries = get_boundaries(my_map_str);
}

t_player	*get_player(char	*my_map_str)
{
	static int	next_rows;
	static int	next_pos;
	static int	found;
	t_player	*player;
	t_coordinate *position;

	while (*my_map_str && !found)
	{
		if (*my_map_str == '\n')
		{
			next_rows++;
			next_pos = 0;
		}
		if (*(my_map_str++) == 'P')
		{
			found = 1;
			continue ;
		}
		next_pos++;
	}
	position = malloc(sizeof(t_coordinate));
	player = malloc(sizeof(t_player));
	position->x = next_pos * 40;
	position->y = next_rows * 40;
	player->position = *position;
	return (player);
}

t_boundary	**get_boundaries(char *my_map_str)
{
	t_boundary **boundaries;
	t_boundary	*row;
	static int	x;
	static int	y;

	boundaries = malloc(sizeof(t_boundary) * num_occurances_c(my_map_str, '\n'));
	row = NULL;
	while (*my_map_str)
	{
		if (*my_map_str == '1')
		{
			row = append_to_row(row, x, y);
		}
		if (*my_map_str == '\n')
		{
			append_to_boundaries(boundaries, row);
			y++;
			x = 0;
		}
		x++;
	}
	return (NULL);
}

t_boundary	*append_to_row(t_boundary *row, int x, int y)
{
	t_boundary		*boundary;
	t_coordinate	*position;
	if (!row)
		row = malloc(sizeof(t_boundary) * 1);
	boundary = malloc(sizeof(t_boundary));
	position = malloc(sizeof(t_coordinate));
	position->x = x * 40;
	position->y = y * 40;
	boundary->position = position;

}
