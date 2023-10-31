/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:54:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 08:09:55 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <math.h>

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
	Testing_one out some stuff
*/
void	draw_square(t_data data, int x, int y, int colors);
void	draw_phrase(t_data data, t_coordinate cds, int colors, char *message);
void	clear_window(t_data data);
void	destroy_window(t_data data);

/*
	Testing_two out some stuff
*/
void	*create_image(t_data data, int width, int height);
void	*xpm_to_image(t_data data, char **xpm_data, int *width, int *height);
void	*file_to_image(t_data data, char *filename, int *width, int *height);
int		destroy_image(t_data data, void *img_ptr);
int		draw_image(t_data data, void *img_ptr, int x, int y);

/*
	Testing_three out some stuff
*/
char	*get_image_info(void *img_ptr, int *bpp, int *sizeline, int *endian);

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
