/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:14:33 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:14:45 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

void	sig_block(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_init(void)
{
	signal(SIGINT, read_again);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_default(t_minishell *m)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &m->term_orig);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
