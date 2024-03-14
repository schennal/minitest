/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:38 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:05:14 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restart_lp(t_minishell *m)
{
	ft_free_all(m->mem);
	free(m->mem);
	free(m->input);
	shell_init(m);
	sig_init();
}

static void	main_loop_process(t_minishell *m)
{
	if (tokenize(m))
	{
		if (m->t_head->next)
		{
			if (m->t_tail->type == TYPE_REDIR_IN)
				ft_putstr_fd(
					"minishell: syntax error near unexpected token `<'\n", 2);
			else
				ft_putstr_fd(
					"minishell:\
                    syntax error near unexpected token `newline'\n", 2);
		}
		restart_lp(m);
		return ;
	}
	if (parse(m))
	{
		ft_putstr_fd(
			"minishell: parsing error\n", 2);
		restart_lp(m);
		return ;
	}
	if (exe(m))
		m->end_stat = 1;
	restart_lp(m);
}

void	main_loop(t_minishell *m)
{
	while (1)
	{
		get_rid_of_sig(m);
		m->input = readline(PROMPT);
		if (!m->input)
		{
			printf("exit\n");
			break ;
		}
		if (m->input[0] == '\0')
		{
			restart_lp(m);
			continue ;
		}
		add_history(m->input);
		if (g_sig == SIGINT)
		{
			m->end_stat = 1;
			g_sig = 0;
		}
		main_loop_process(m);
	}
}
