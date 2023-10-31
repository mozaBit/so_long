/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:19 by bmetehri          #+#    #+#             */
/*   Updated: 2022/11/11 14:04:51 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*ss;

	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)ss)[i] == (unsigned char)c)
		{
			while (i)
			{
				ss++;
				i--;
			}
			return (ss);
		}
		i++;
	}
	return (NULL);
}
