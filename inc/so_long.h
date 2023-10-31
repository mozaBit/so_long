/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:54:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 11:43:00 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
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

typedef struct s_player
{
	t_coordinate	position;
}	t_player;

typedef struct s_boundary
{
	t_coordinate	position;

}	t_boundary;

typedef struct s_map
{
	t_player	player;
	int			width;
	int			height;
	t_boundary	*boundaries;
}	t_map;

/*
	Parsing Map
*/
void	check_args(int ac, char **av);

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

/*
	Keys
*/
# define XK_SW 0x0077  /* U+0077 LATIN SMALL LETTER W */
# define XK_SA 0x0061  /* U+0061 LATIN SMALL LETTER A */
# define XK_SS 0x0073  /* U+0073 LATIN SMALL LETTER S */
# define XK_SD 0x0064  /* U+0064 LATIN SMALL LETTER D */

# define XK_LEFT  0xff51  /* Move left, left arrow */
# define XK_UP    0xff52  /* Move up, up arrow */
# define XK_RIGHT 0xff53  /* Move right, right arrow */
# define XK_DOWN  0xff54  /* Move down, down arrow */

#endif
