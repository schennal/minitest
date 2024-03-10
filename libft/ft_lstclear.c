/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:15:42 by schennal          #+#    #+#             */
/*   Updated: 2023/02/10 13:12:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nlist;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nlist = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nlist;
	}
	*lst = NULL;
}
