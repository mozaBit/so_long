/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:31:17 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/01 20:52:59 by bmetehri         ###   ########.fr       */
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
