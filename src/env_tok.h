/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tok.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:07 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:35:18 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TOK_H
# define ENV_TOK_H
# include "env.h"

int		count(t_token *tok, bool is_div);
void	get_idx(t_token *tok, t_env *env);
#endif