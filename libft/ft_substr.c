/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:28:20 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/05 19:12:10 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*orig;
	size_t	i;

	orig = (char *)s;
	if (start >= ft_strlen(orig) || !len)
		return (ft_calloc(1, 1));
	if (len + start > ft_strlen(orig))
		len = ft_strlen(orig) - start;
	str = ft_calloc((len + 1) * sizeof(char), 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (orig[i + start] && i < len)
	{
		str[i] = orig[start + i];
		i++;
	}
	return (str);
}
