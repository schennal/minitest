/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:13:21 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:13:58 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	shell_malloc(t_minishell *m)
{
	m->mem = ft_lstnew(NULL);
	if (!m->mem)
		return (1);
	m->t_head = ft_malloc(sizeof(t_token), m->mem);
	if (!m->t_head)
		return (1);
	m->path = ft_malloc(PATH_MAX, m->mem);
	if (!m->path)
		return (1);
	return (0);
}

bool	shell_init(t_minishell *m)
{
	m->a_size = 0;
	m->b_size = 0;
	m->input = NULL;
	if (shell_malloc(m))
		return (1);
	m->t_head->next = NULL;
	m->t_head->cont = NULL;
	m->t_head->end_pos = -100;
	m->t_tail = m->t_head;
	m->exe_idx = 0;
	m->exe_size = 0;
	m->is_print_sig = 1;
	return (0);
}

bool	env_init(t_minishell *m)
{
	int		i;
	int		j;
	char	**env_tmp;
	int		env_size;

	i = 0;
	while (environ[i])
		i++;
	env_tmp = ft_malloc(sizeof(char *) * ++i, m->mem_env);
	if (!env_tmp)
		return (1);
	m->env_size = i;
	j = 0;
	while (j < i - 1)
	{
		env_size = ft_strlen(environ[j]) + 1;
		env_tmp[j] = ft_malloc(env_size, m->mem_env);
		if (!env_tmp[j])
			return (1);
		ft_strlcpy(env_tmp[j], environ[j], env_size);
		j++;
	}
	env_tmp[j] = NULL;
	environ = env_tmp;
	return (0);
}
