/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:20:57 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:21:03 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "minishell.h"

bool	exe_init(t_minishell *m);
bool	exe_cmd(t_minishell *m);
bool	exe_rdin(t_minishell *m);
bool	exe_rdout(t_minishell *m);
bool	exe_ap(t_minishell *m);
void	exe_rdr(t_minishell *m);
bool	exe_hdc(t_minishell *m);
bool	exe_pipe(t_minishell *m, int idx);
void	b_echo(t_minishell *m, int idx);
void	b_cd(t_minishell *m, int idx);
void	b_export(t_minishell *m, int idx);
void	b_unset(t_minishell *m, int idx);
void	b_env(t_minishell *m, int idx);
void	b_exit(t_minishell *m, int idx, bool is_print);
void	exe_builtin(t_minishell *m, int idx, bool is_print);
void	start_exe_cmd(t_minishell *m, int idx);
char	**get_path(t_minishell *m, char *cmd);
void	cd_error_special(t_minishell *m);
void	b_cd_handle(t_minishell *m, int idx);
void	mod_env_cd(t_minishell *m, char *old_pwd);
void	cd_error(t_minishell *m, int idx);
void	mod_env_cd_special(t_minishell *m, char *old_pwd);
void	b_cd_home(t_minishell *m, int idx);
void	is_a_dir(char *str);
void	check_if_dir(char *cmd);

#endif