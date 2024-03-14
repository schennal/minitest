/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:51:00 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 14:56:24 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_minishell	m;

	sig_init();
	get_rid_of_sig(&m);
	m.end_stat = 0;
	m.mem_env = ft_lstnew(NULL);
	if (!m.mem_env)
	{
		perror("minishell");
		exit(1);
	}
	shell_init(&m);
	if (env_init(&m))
	{
		perror("minishell");
		exit(1);
	}
	start_env(&m);
	main_loop(&m);
	ft_free_all(m.mem_env);
	exit(0);
}
