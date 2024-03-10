/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:37:38 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 13:55:50 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_sigint(int signum)
{
	(void)signum;
	ft_clean_ms();
	exit(SIGINT);
}

void	handle_heredoc(t_io_node *io, int p[2])
{
	char	*line;
	char	*quotes;

	signal(SIGINT, handle_heredoc_sigint);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (check_delimiter(io->value, line))
			break ;
		if (!*quotes)
			expand_heredoc(line, p[1]);
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	ft_clean_ms();
	exit(0);
}