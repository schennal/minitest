/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:07:29 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:19:03 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*temp;

	if (!(f) || !(del) || !lst)
		return (NULL);
	nlist = ft_lstnew(f(lst->content));
	if (!nlist)
		return (NULL);
	temp = nlist;
	lst = lst->next;
	while (lst)
	{
		nlist->next = ft_lstnew(f(lst->content));
		if (!nlist->next)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		nlist = nlist->next;
		lst = lst->next;
	}
	nlist->next = NULL;
	return (temp);
}
