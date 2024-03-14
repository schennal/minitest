/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:07:55 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 17:15:39 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void *ptr, t_list *mem)
{
	t_list	*prev;

	if (!mem || !ptr)
		return ;
	prev = mem;
	mem = mem->next;
	while (mem)
	{
		if (mem->content == ptr)
		{
			prev->next = mem->next;
			ft_lstdelone(mem, &free);
			break ;
		}
		prev = mem;
		mem = mem->next;
	}
}

void	ft_free_all(t_list *mem)
{
	if (!mem)
		return ;
	ft_lstclear(&mem->next, &free);
}

void	*ft_malloc(size_t size, t_list *mem)
{
	void	*new;
	t_list	*tail;

	new = malloc(size);
	if (!new)
	{
		ft_free_all(mem);
		return (NULL);
	}
	tail = ft_lstlast(mem);
	tail->next = ft_lstnew(new);
	return (new);
}

