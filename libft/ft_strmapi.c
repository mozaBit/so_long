/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:46:03 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/05 19:06:34 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r_str;
	unsigned int	i;

	r_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	r_str[ft_strlen(s)] = '\0';
	i = 0;
	while (s[i])
	{
		r_str[i] = f(i, s[i]);
		i++;
	}
	return (r_str);
}
