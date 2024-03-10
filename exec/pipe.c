/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:40:56 by schennal          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:13 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void handle_pipe_child(t_node *node, int pfds[2], t_ast_direction direction)
{
	int	status;

	if (direction == OUT_RD)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
	}
	else if (direction == IN_RD)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
	}
	status = handle_execution(node, true);
	(ft_clean_ms(), exit(status));
}

int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

int	handle_pipe(t_node *tree)
{
	int	status;
	int	pfds[2];
	int	pid_l;
	int	pid_r;

	g_minishell.sigint = true;
	pipe(pfds);
	pid_l = fork();
	if (!pid_l)
		handle_pipe_child(tree->left, pfds, IN_RD);
	else
	{
		pid_r = fork();
		if (!pid_r)
			handle_pipe_child(tree->right, pfds, OUT_RD);
		else
		{
			(close(pfds[0]), close(pfds[1]),
				waitpid(pid_l, &status, 0), waitpid(pid_r, &status, 0));
			g_minishell.sigint = false;
			return (ft_get_exit_status(status));
		}
	}
	return (ENO_GENERAL);
}