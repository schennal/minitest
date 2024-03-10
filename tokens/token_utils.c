/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:12:43 by pamone            #+#    #+#             */
/*   Updated: 2024/02/20 15:58:11 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <limits.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(int count, int size)
{
	void	*tmp;

	if (count == INT_MAX || size == INT_MIN)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	return (ft_memset(tmp, 0, size * count));
}

t_token	*ft_new_token(char *str, t_token_id id_type)
{
    t_token *new_token;

	new_token = (t_token *)calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = str;
	new_token->type = id_type;
	return (new_token);

}

void	ft_append_token(t_token **head, t_token *new_token)
{
	t_token *token;

	if(!*head)
	{
		*head = new_token;
		return;
	}
	token = *head;
	while(token && token->next)
		token = token->next;
	token->next = new_token;
	new_token->prev = token;
}
void	ft_free_token(t_token **tokens)
{
	t_token *node;
	t_token *next;
	node = *tokens;
	while(node)
	{
		free(node->value);
		next = node->next;
		free(node);
		node = next;
	}
	*tokens = NULL;
}
