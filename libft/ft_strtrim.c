/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:37:39 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/03 16:17:54 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	length;
	int	start;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	length = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[length]) && s1[length])
		length--;
	return (ft_substr(s1, start, length - start + 1));
}
