/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:22:26 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 09:32:37 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_founded(t_nlist *mylist)
{
	int		i;
	t_nlist	*current;

	if (mylist == NULL)
		return (0);
	current = ft_lst_get_last(mylist);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_nlist	*ft_lst_get_last(t_nlist *mylist)
{
	t_nlist	*current;

	current = mylist;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	allocate_memory_to_line(char **line, t_nlist *mylist)
{
	int	i;
	int	len;

	len = 0;
	while (mylist)
	{
		i = 0;
		while (mylist->content[i])
		{
			if (mylist->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		mylist = mylist->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen2(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_list(t_nlist *mylist)
{
	t_nlist	*current;
	t_nlist	*next;

	current = mylist;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
