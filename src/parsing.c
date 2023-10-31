/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:06:34 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 11:25:42 by bmetehri         ###   ########.fr       */
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
