/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:49:21 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:50 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	if (big[0] == '\0')
		return (NULL);
	while (i < len && big[i])
	{
		j = 0;
		if (little[j] == big[i])
		{
			while (i + j < len && little[j] && little[j] == big[i + j])
				j++;
			if (j == ft_strlen(little))
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
