/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:54:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 18:19:32 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_map
{
	char			**map_strs;
	int				rows;
	int				columns;
	int				collectables;
	int				exit;
	int				characters;
	t_coordinate	character;
}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		movements;
	int		character_sheet;
	bool	map_allocated;
	t_image	boundary;
	t_image	ground;
	t_image	collectable;
	t_image	o_exit;
	t_image	c_exit;
	t_image	c_front;
	t_image	c_left;
	t_image	c_back;
	t_image	c_right;

}	t_game;

/*
	Parsing Map
*/
void		ft_check_args(int ac, char **av, t_game *game);
void		init_map(char *av, t_game *game);
void		vars_init(t_game *game);
void		check_map(t_game *game);
// void		create_map(t_data data, char *filename);
// char		*get_my_map_str(int fd);


/*
	Testing_one out some stuff
*/
void		draw_square(t_data data, int x, int y, int colors);
void		draw_phrase(t_data data, t_coordinate cds, int colors, char *message);
void		clear_window(t_data data);
void		destroy_window(t_data data);

/*
	Testing_two out some stuff
*/
void		*create_image(t_data data, int width, int height);
void		*xpm_to_image(t_data data, char **xpm_data, int *width, int *height);
void		*file_to_image(t_data data, char *filename, int *width, int *height);
int			destroy_image(t_data data, void *img_ptr);
int			draw_image(t_data data, void *img_ptr, int x, int y);

/*
	Testing_three out some stuff
*/
char		*get_image_info(void *img_ptr, int *bpp, int *sizeline, int *endian);
int			num_occurances_c(char *str ,char c);
void		error_print(char *msg, t_game *game);
void		check_map_errors(char *map, t_game *game);
char		*ft_strappend(char **s1, const char *s2);

/*
	Initializers
*/
t_image		init_new_sprite(void	*mlx, char *path, t_game *game);
void		initilize_mlx(t_game *game);
void		initialize_sheets(t_game *game);

/*
	Checkers
*/
void		check_rows(t_game *game);
void		check_columns(t_game *game);
void		count_params(t_game *game);
void		verify_params(t_game *game);

/*
	Rendering
*/
void		print_movements(t_game *game);
int			render_everything(t_game *game);
void		render_spritesheet(t_game *game, t_image img, int j, int i);
void		get_spritesheet(t_game *game, int i, int j);
void		render_character(t_game *game, int j, int i);

/*
	Handlers
*/
void		player_move(t_game *game, int n_j, int n_i, int sprite);
int			handle_input(int key, t_game *game);

/*
	Closing game
*/
int			victory(t_game *game);
int 		close_game(t_game *game);

/*
	freeing
*/

void 		end_imgs(t_game *game);
void 		free_maps(t_game *game);
void		free_stuffs(t_game *game);

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
	Print Colors
*/
# define P_GREEN			"\033[0;32m"
# define P_RED 				"\033[1;31m"
# define P_GREY 			"\033[0;90m"
# define P_CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

/*
	Character Positions
*/
# define FRONT		1
# define BACK		2
# define RIGHT		3
# define LEFT		4

/*
	Keys
*/
# define KEY_SW 0x0077  /* U+0077 LATIN SMALL LETTER W */
# define KEY_SA 0x0061  /* U+0061 LATIN SMALL LETTER A */
# define KEY_SS 0x0073  /* U+0073 LATIN SMALL LETTER S */
# define KEY_SD 0x0064  /* U+0064 LATIN SMALL LETTER D */

# define KEY_CW 0x0057  /* U+0057 LATIN CAPITAL LETTER W */
# define KEY_CA 0x0041  /* U+0041 LATIN CAPITAL LETTER A */
# define KEY_CS 0x0053  /* U+0053 LATIN CAPITAL LETTER S */
# define KEY_CD 0x0044  /* U+0044 LATIN CAPITAL LETTER D */

# define KEY_LEFT  0xff51  /* Move left, left arrow */
# define KEY_UP    0xff52  /* Move up, up arrow */
# define KEY_RIGHT 0xff53  /* Move right, right arrow */
# define KEY_DOWN  0xff54  /* Move down, down arrow */

# define KEY_CQ		0x0051	/* U+0051 LATIN CAPITAL LETTER W */
# define KEY_SQ		0x0071	/* U+0071 LATIN SMALL LETTER W */
# define KEY_ESC		0xff1b  /* Escape Char */

/*
	SpriteSheets
*/
# define BOUNDARY_XPM		"imgs/ground/boundary.xpm"
# define GROUND_XPM			"imgs/ground/ground.xpm"
# define COLLECTABLE_XPM	"imgs/collectable/coins.xpm"
# define P_FRONT_XPM		"imgs/sprite/front.xpm"
# define P_BACK_XPM			"imgs/sprite/back.xpm"
# define P_RIGHT_XPM		"imgs/sprite/right.xpm"
# define P_LEFT_XPM			"imgs/sprite/left.xpm"
# define O_EXIT				"imgs/exit/o_exit.xpm"
# define C_EXIT				"imgs/exit/c_exit.xpm"

/*
	Terms
*/
# define BOUNDARY		'1'
# define COLLECTABLE	'C'
# define GROUND			'0'
# define CHARACTER		'P'
# define M_EXIT			'E'

/*
	STANDARDS
*/
# define S_WIDTH	40
# define S_HEIGHT	40

#endif
