/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:07:14 by pamone            #+#    #+#             */
/*   Updated: 2024/02/22 05:03:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ft_set_parse_err(t_err_type err)
{
    //g.minishell.parse_err.type = err;
}

void    ft_handle_parse_err(void)
{
    t_err_type      type;
    t_token_id      token_id;
    char            **types;

    types = (char *[]){"&&", "<<", ">>", "<", ">", "(", ")", "||", "|", "newline","IDENTIFIER", NULL};
    type = g_minishell.parse_err.type;
    (void)token_id;
    (void)types;
    if(types)
    {
        if(type == SYNTAX)
        {
            if(!g_minishell.parse_err.token)
                token_id = NL;
            else
               token_id = g_minishell.parse_err.token->type;
            ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
            ft_putstr_fd(types[token_id], 2);
            ft_putstr_fd("'\n", 2);
            g_minishelll.exit_status = 258;
        }
        ft_free_ast(&g_minishell.ast);
        ft_bzero(&g_minishell.parse_err, sizeof(t_parse_error));
    }
}