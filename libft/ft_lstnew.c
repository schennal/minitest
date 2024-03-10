/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:42:31 by schennal          #+#    #+#             */
/*   Updated: 2023/02/05 16:27:22 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->content = content;
	nlist->next = NULL;
	return (nlist);
}
