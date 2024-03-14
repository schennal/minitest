/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:08:16 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 16:08:28 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	b_cd_home(t_minishell *m, int idx)
{
	if (chdir(getenv("HOME")) != 0)
		cd_error(m, idx);
	mod_env_cd(m, getenv("PWD"));
}

