/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:32:18 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:32:21 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_STR_H
# define ENV_STR_H
# include "env.h"

int		count_str(char *str);
void	get_idx_str(char *str, t_env *env);

#endif