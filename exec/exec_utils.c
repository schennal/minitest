/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:39:19 by schennal          #+#    #+#             */
/*   Updated: 2024/03/07 20:20:12 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*ft_cleanup(void *ptr, bool clean)
{
	static t_list	*clean_list;

	if (clean)
	{
		ft_lstclear(&clean_list, free_ptr);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&clean_list, ft_lstnew(ptr));
		return (ptr);
	}
}

bool	check_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!*delimiter);
}

static void	ft_clear_envlst(void)
{
	t_env	*env_list;
	t_env	*env_list_tofree;

	env_list = g_minishell.env_list;
	while (env_list)
	{
		env_list_tofree = env_list;
		env_list = env_list->next;
		free(env_list_tofree);
	}
	g_minishell.env_list = NULL;
}

void	ft_clean_ms(void)
{
	ft_cleanup(NULL, true);
	ft_free_ast(&g_minishell.ast);
	ft_clear_envlst();
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell.og_terminal);
}
