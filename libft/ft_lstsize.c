/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:12:09 by bmetehri          #+#    #+#             */
/*   Updated: 2022/11/23 11:20:53 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		size;

	list = lst;
	size = 0;
	if (!lst)
		return (0);
	size++;
	while (list->next)
	{
		size++;
		list = list->next;
	}
	return (size);
}
