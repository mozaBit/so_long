/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:21:43 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 09:33:18 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_nlist	*mylist;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_stack(fd, &mylist);
	if (mylist == NULL)
		return (NULL);
	get_line(mylist, &line);
	clean_list(&mylist);
	if (line[0] == '\0')
	{
		free_list(mylist);
		mylist = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stack(int fd, t_nlist **mylist)
{
	int		readed_chars;
	char	*buffer;

	readed_chars = 1;
	while (!new_line_founded(*mylist) && readed_chars != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		readed_chars = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*mylist == NULL && readed_chars == 0) || readed_chars == -1)
		{
			free(buffer);
			return ;
		}
		buffer[readed_chars] = '\0';
		add_to_mylist(mylist, buffer, readed_chars);
		free(buffer);
	}
}

void	add_to_mylist(t_nlist **mylist, char *buffer, int readed_chars)
{
	t_nlist	*last_node;
	t_nlist	*new_node;
	int		i;

	new_node = malloc(sizeof(t_nlist));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed_chars + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < readed_chars)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*mylist == NULL)
	{
		*mylist = new_node;
		return ;
	}
	last_node = ft_lst_get_last(*mylist);
	last_node->next = new_node;
}

void	get_line(t_nlist *mylist, char **line)
{
	int	i;
	int	j;

	allocate_memory_to_line(line, mylist);
	if (*line == NULL)
		return ;
	j = 0;
	while (mylist)
	{
		i = 0;
		while (mylist->content[i])
		{
			if (mylist->content[i] == '\n')
			{
				(*line)[j++] = mylist->content[i];
				break ;
			}
			(*line)[j++] = mylist->content[i++];
		}
		mylist = mylist->next;
	}
	(*line)[j] = '\0';
}

void	clean_list(t_nlist **mylist)
{
	int		i;
	int		j;
	t_nlist	*last;
	t_nlist	*pure;

	pure = malloc(sizeof(t_nlist));
	if (pure == NULL || mylist == NULL)
		return ;
	pure->next = NULL;
	last = ft_lst_get_last(*mylist);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	pure->content = malloc(sizeof(char) * (ft_strlen2(last->content) - i) + 1);
	if (pure->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		pure->content[j++] = last->content[i++];
	pure->content[j] = '\0';
	if (*mylist)
		free_list(*mylist);
	*mylist = pure;
}
