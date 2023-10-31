/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:46:22 by bmetehri          #+#    #+#             */
/*   Updated: 2023/01/02 12:54:16 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*returned_lst;

	if (!lst || !f)
		return (NULL);
	returned_lst = ft_lstnew(f(lst->content));
	if (returned_lst->content == NULL)
	{
		ft_lstdelone(returned_lst, del);
		return (NULL);
	}
	if (!lst->next)
	{
		returned_lst->next = NULL;
		return (returned_lst);
	}
	returned_lst->next = ft_lstmap(lst->next, f, del);
	if (returned_lst->next == NULL)
	{
		ft_lstdelone(returned_lst, del);
		return (NULL);
	}
	return (returned_lst);
}
