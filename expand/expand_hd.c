/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_HD.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:13:02 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 14:13:03 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static int handle_heredoc_str(char *str, size_t i, int fd)
{
    size_t	index;
	char	*tmp;

	index = ++i;
	if (str[i] == '?')
		return (ft_putnbr_fd(g_minishell.exit_status, fd), 2);
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	if (i != index)
	{
		tmp = ft_cleanup(ft_substr(str, index, i), false);
		tmp = ft_get_envlst_val(tmp);
		if (tmp)
			ft_putstr_fd(tmp, fd);
	}
	return (i);
}

void    expand_heredoc(char *str, int fd)
{
    size_t  i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '$')
            i += handle_heredoc_str(str, i, fd);
        else
            i += (ft_putchar_fd(str[i], fd), 1);
    }
    ft_putchar_fd('\n', fd);
}
