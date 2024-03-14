/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:32:43 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:32:50 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"

typedef struct s_env
{
	char	*cont;
	int		*idx;
	int		num;
}				t_env;

char	*get_name(t_minishell *m, t_env *env, char *str, int idx);
bool	copy_env(t_minishell *m, t_env *env, char *env_cont);
char	*get_cont(t_minishell *m, char *name);
#endif