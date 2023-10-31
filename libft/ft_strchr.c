/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:52:15 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/03 18:40:41 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	if (!s)
		return (NULL);
	ss = (char *)s;
	i = 0;
	while (ss[i] && ss[i] != (unsigned char)c)
		i++;
	if (ss[i] == (unsigned char)c)
		return (&ss[i]);
	return (NULL);
}
