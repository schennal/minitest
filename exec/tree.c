/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:10:35 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 14:47:02 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

static bool	clean_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	g_minishell.sigint = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

static void	handle_leaf(t_node *node)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HERE_DOC)
		{
			pipe(p);
			g_minishell.sigint = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				handle_heredoc(io, p);
			if (clean_leaf(p, &pid))
				return ;
			io->here_doc = p[0];//p[0] is the read end
		}
		else
			io->expanded_value = expand_str(io->value);
		io = io->next;
	}
}

void handle_tree(t_node *node)
{
    if (!node)
        return ;
    if (node->type == NODE_PIPE || node->type == NODE_AND || node->type == NODE_OR)
    {
        handle_tree(node->left);
        if(!g_minishell.sigint_heredoc)
            handle_tree(node->right);
    }
    else
        handle_leaf(node);
}
