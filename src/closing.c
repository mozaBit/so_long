/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:15:46 by bmetehri          #+#    #+#             */
/*   Updated: 2023/11/13 18:13:26 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	victory(t_game *game)
{
	ft_printf(P_GREEN"\nMovements: %d\n"RESET, game->movements + 1);
	free_stuffs(game);
	ft_printf(P_GREEN"\nYOU WON !\n");
	exit (0);
}

int close_game(t_game *game)
{
	ft_printf(P_GREEN"\nMovements: %d\n"RESET, game->movements);
	free_stuffs(game);
	ft_printf(P_GREEN"\nClosed game, relunch !\n");
	exit (1);
}
