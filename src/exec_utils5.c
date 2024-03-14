/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:58:12 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:58:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

static void	cmd_not_found(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (errno == 2)
		exit(127);
	exit(1);
}

static void	no_such_file(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(127);
}

static void	exe_absolute(t_minishell *m, int idx)
{
	check_if_dir(m->exe[idx].args[0]);
	execve(m->exe[idx].args[0], m->exe[idx].args, environ);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(m->exe[idx].args[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	if (errno == 13)
		exit(126);
	if (errno == 2)
		exit(127);
	exit(errno);
}

static void	exe_path(t_minishell *m, int idx)
{
	int			i;
	char		**path;

	path = get_path(m, m->exe[idx].args[0]);
	exe_builtin(m, idx, 0);
	if (!path)
		no_such_file(m->exe[idx].args[0]);
	i = 0;
	while (path[i])
	{
		check_if_dir(path[i]);
		if (access(path[i], X_OK) == 0)
		{
			execve(path[i], m->exe[idx].args, environ);
			perror("minishell");
			exit(errno);
		}
		i++;
	}
}

void	start_exe_cmd(t_minishell *m, int idx)
{
	if (ft_strchr(m->exe[idx].args[0], '/'))
		exe_absolute(m, idx);
	else
		exe_path(m, idx);
	cmd_not_found(m->exe[idx].args[0]);
}
