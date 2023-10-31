/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:51:09 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 13:43:30 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	main(int ac, char **av)
// {
// 	// t_map	*my_map;
// 	t_data	data;

// 	check_args(ac, av);
// 	data.mlx_ptr = mlx_init();
// 	// my_map = create_map(&data, av[1]);
// }

/*

	** Testing ...
	void *
	mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
*/
int	main(int ac, char **av)
{
	t_data			data;
	t_coordinate	text_xy;

	check_args(ac, av);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 64 * 16, 64 * 9, "Test");
	draw_square(data, 75, 75, OLIVE);
	text_xy.x = 50;
	text_xy.y = 50;
	draw_phrase(data, text_xy, WHITE, "Hello There !");
	sleep(5);
	clear_window(data);
	sleep(2);
	destroy_window(data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

