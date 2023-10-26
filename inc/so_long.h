/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:54:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/26 20:23:25 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

/*
	Testing out some stuff
*/
void	draw_square(t_data data, int x, int y, int colors);
void	draw_phrase(t_data data, t_coordinate cds, int colors, char *message);
void	clear_window(t_data data);
void	destroy_window(t_data data);

/*
	Colors
*/
# define WHITE 0xFFFFFF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define BLACK 0x000000
# define RED 0xFF0000
# define MAROON 0x800000
# define YELLOW 0xFFFF00
# define OLIVE 0x808000
# define LIME 0x00FF00
# define GREEN 0x008000
# define AQUA 0x00FFFF
# define TEAL 0x008080
# define BLUE 0x0000FF
# define NAVY 0x000080
# define FUCHSIA 0xFF00FF
# define PURPLE 0x800080

#endif
