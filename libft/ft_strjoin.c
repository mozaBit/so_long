/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:12:56 by bmetehri          #+#    #+#             */
/*   Updated: 2022/12/23 18:50:01 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*returned_str;
	int		i;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	returned_str = malloc((length + 1) * sizeof(char));
	if (!returned_str)
		return (NULL);
	returned_str[length] = '\0';
	i = 0;
	while (*s1)
		returned_str[i++] = *(s1++);
	while (*s2)
		returned_str[i++] = *(s2++);
	return (returned_str);
}
