/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:46:35 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/03 18:26:22 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ss;

	if (!s)
		return (NULL);
	ss = (unsigned char *)s;
	while (n--)
	{
		*ss++ = (unsigned char) c;
	}
	return (s);
}
