/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:38:59 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:57:22 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **store_env(char **environ, int extra)
{
    int i;
    int len;
    char **array;

    len = get_array_len(environ);
    array = (char **)ft_calloc(sizeof(char *), (len, extra, + 1));
    if (!array)
        return (0);
    i = 0;
    while(i < len)
    {
        array[i] = ft_strdup(environ[i]);
        i++;
    }
    return(array);
}

void	ft_envlst_back(t_env *new)
{
	t_env	*curr;

	if (!g_minishell.env_list)
	{
		g_minishell.env_list = new;
		return ;
	}
	curr = g_minishell.env_list;
	while (curr && curr->next)
		curr = curr->next;
    curr->next = new;
}
	

void	ft_update_envlst(char *key, char *value, bool create)
{
	t_env	*envlst;

	envlst = g_minishell.env_list;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
				envlst->value = ft_cleanup(ft_strdup(value), false);
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		ft_envlst_back(ft_envlst_new(key, value));
}