/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:22:45 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/31 09:32:22 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct m_list
{
	char			*content;
	struct m_list	*next;
}					t_nlist;

char	*get_next_line(int fd);
void	read_and_stack(int fd, t_nlist **mylist);
int		new_line_founded(t_nlist *mylist);
t_nlist	*ft_lst_get_last(t_nlist *mylist);
void	add_to_mylist(t_nlist **mylist, char *buffer, int readed_chars);
void	get_line(t_nlist *mylist, char **line);
void	allocate_memory_to_line(char **line, t_nlist *mylist);
void	clean_list(t_nlist **mylist);
int		ft_strlen2(char *str);
void	free_list(t_nlist *mylist);

#endif
