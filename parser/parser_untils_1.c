/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_untils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:52:58 by pamone            #+#    #+#             */
/*   Updated: 2024/02/22 04:10:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
**	Checks if the token is a delimiter

*/
t_type	ft_get_node_type(t_token_id id)
{
	if(id == AND)
		return (NODE_AND);
	if (id == OR)
		return (NODE_OR);
	return (NODE_PIPE);
	
}
/*
**	Checks if the token is a delimiter
*/
t_io_type	ft_get_io_type(t_token_id id)
{
	if(id == INPUT)
		return (IO_IN);
	if (id == OUTPUT)
		return (IO_OUT);
	if (id == HERE_DOC)
		return (IO_HERE_DOC);
	return (IO_APPEND);
}

t_node	*ft_new_node(t_type type)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if(!new_node)
		return (NULL);
	new_node->type = type;
	return (new_node);
}

t_io	*ft_new_io(t_token_id type, char *file)
{
	t_io	*new_io;

	new_io = (t_io *)malloc(sizeof(t_io));
	if(!new_io)
		return (NULL);
	new_io->type = ft_get_io_type(type);
	new_io->value = ft_strdup(file);
	if(!new_io->value)
		return (free(new_io), NULL);
	return (new_io);
}

void	ft_append_io_node(t_io **list, t_io *new_io)
{
	t_io	*tmp;

	if(!*list)
	{
		*list = new_io;
		return ;
	}
	tmp = *list;
	while(tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_io;
}