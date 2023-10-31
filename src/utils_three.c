/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:31:17 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 08:11:18 by bmetehri         ###   ########.fr       */
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
