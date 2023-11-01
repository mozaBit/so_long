/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:44:33 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/01 20:52:52 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
	** Testing ...
	void *
	mlx_new_image(void *mlx_ptr, int width, int height);
*/
void	*create_image(t_data data, int width, int height)
{
	return (mlx_new_image(data.mlx_ptr, width, height));
}

/*
	** Testing ...
	void *
	mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
*/
void	*xpm_to_image(t_data data, char **xpm_data, int *width, int *height)
{
	return (mlx_xpm_to_image(data.mlx_ptr, xpm_data, width, height));
}

/*
	** Testing ...
	void *
	mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
*/
void	*file_to_image(t_data data, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(data.mlx_ptr, filename, width, height));
}

/*
	** Testing ...
	int
	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
*/
int	destroy_image(t_data data, void *img_ptr)
{
	return (mlx_destroy_image(data.mlx_ptr, img_ptr));
}

/*
	** Testing ...
	int
	mlx_put_image_to_window
			(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
*/
int	draw_image(t_data data, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y));
}
