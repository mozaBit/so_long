/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:31:17 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/12 23:09:32 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
	** Testing ...
	void *
	mlx_get_data_addr
			(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
*/
char	*get_image_info(void *img_ptr, int *bpp, int *sizeline, int *endian)
{
	return (mlx_get_data_addr(img_ptr, bpp, sizeline, endian));
}

int	num_occurances_c(char *str ,char c)
{
	int	occ;

	if (!str)
		return (0);
	occ = 0;
	while (*str){
		if (*str == c)
			occ++;
		str++;
	}
	return (occ);
}
void	error_print(char *msg, t_game *game)
{
	if (game->map_allocated == true)
		free_map(game);
	free(game);
	ft_printf(P_RED"%s\n"RESET, msg);
	exit(1);
}

void	check_map_errors(char *map, t_game *game)
{
	int	idx;

	idx = 0;
	if (map[0] == '\n')
	{
		free(map);
		error_print("Error: Invalid Map: Map cannot start with \\n", game);
	}
	if (map[ft_strlen2(map) - 1] == '\n')
	{
		free(map);
		error_print("Error: Invalid Map: Map cannot terminate with \\n", game);
	}
	while (map[idx + 1])
	{
		if (map[idx] == '\n' && map[idx + 1] == '\n')
		{
			free(map);
			error_print("Error: Invalid Map: Map cannot have two consicutives \\n", game);
		}
		idx++;
	}
}
