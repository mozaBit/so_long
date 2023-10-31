/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:55 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/03 18:43:52 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ss;

	if (!s)
		return (NULL);
	ss = (char *)s;
	len = ft_strlen(ss);
	while (len >= 0 && ss[len] != (unsigned char)c)
		len--;
	if (len < 0)
		len = 0;
	if (ss[len] == (unsigned char)c)
		return (&ss[len]);
	return (NULL);
}
