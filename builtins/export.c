/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:48:32 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:53:42 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_export_err_msg(char *identifier)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static	void	ft_export_list(void)
{
	t_env	*list;
	size_t	i;

	list = g_minishell.env_list;
	while (list)
	{
		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
		{
			printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					printf("\\%c", (list->value)[i++]);
				else
					printf("%c", (list->value)[i++]);
			}
			printf("\"\n");
		}
		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
			printf("declare -x %s\n", list->key);
		list = list->next;
	}
}


int	ft_export(char **argv)
{
	int		i;
	int		exit_status;
	char	*key;

	exit_status = 0;
	i = 1;
	if (!argv[1])
		return (ft_export_list(), 0);
	while (argv[i])
	{
		if (ft_check_key(argv[i]) == 0)
			exit_status = ft_export_err_msg(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (ft_env_entry_exists(key))
				ft_update_envlst(key, ft_extract_value(argv[i]), false);
			else
				ft_update_envlst(key, ft_extract_value(argv[i]), true);
		}
		i++;
	}
	return (exit_status);
}