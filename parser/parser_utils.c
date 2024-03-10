/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:34 by pamone            #+#    #+#             */
/*   Updated: 2024/02/22 05:23:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
/*
**  ft_get_next_token:
**  This function is used to get the next token from the token list.
**  It will set the current token to the next token in the list.
**  If the current token is NULL, it will return NULL.

**  @return: void
**  ft_get_io_list:
**  This function is used to get the io list from the token list.
**  It will iterate through the token list and get the io list.
**  If the current token is NULL, it will return NULL.
**  If the current token is not an io, it will return NULL.
**  If the current token is an io, it will add it to the io list.
**  If the current token is an io, it will set the current token to the next token in the list.
**  If the current token is NULL, it will return NULL.
**  If the current token is not an io, it will return NULL.
**  If the current token is an io, it will add it to the io list.


*/
bool    ft_get_io_list(t_io **io_list)
{
    t_token_id re_dir_type;
    t_io        *node_io;

    if (g_minishell.parse_err.type)
        return (false);
    while (g_minishell.curr_token && ft_is_redir(g_minishell.curr_token->type))
    {
        re_dir_type = g_minishell.curr_token->type;
        ft_get_next_token();
        if (!g_minishell.curr_token)
            return (ft_set_parse_err(SYNTAX), false);
        if (g_minishell.curr_token->type != IDENTIFIER)
            return (ft_set_parse_err(SYNTAX), false);
        node_io = ft_new_io(re_dir_type, g_minishell.curr_token->value);
        if(!node_io)
            return (ft_set_parse_err(MEM), false); 
        ft_append_io_node(io_list, node_io);
        ft_get_next_token();  
    }
    
}

// bool    ft_get_cmd(t_node **cmd)
// {
//     t_node  *node_cmd;
//     t_io    *io_list;

//     if (g_minishell.parse_err.type)
//         return (false);
//     if (!g_minishell.curr_token)
//         return (ft_set_parse_err(SYNTAX), false);
//     if (g_minishell.curr_token->type != IDENTIFIER)
//         return (ft_set_parse_err(SYNTAX), false);
//     node_cmd = ft_new_node_cmd(g_minishell.curr_token->value);
//     if(!node_cmd)
//         return (ft_set_parse_err(MEM), false);
//     ft_get_next_token();
//     if (g_minishell.curr_token && g_minishell.curr_token->type == REDIR)
//     {
//         if (!ft_get_io_list(&io_list))
//             return (false);
//         node_cmd->io_list = io_list;
//     }
//     *cmd = node_cmd;
//     return (true);
// }
bool    ft_join_args(char **args)
{
    char    *to_free;

    if (!g_minishell.parse_err.type)
        return (false);
    if (!*args)
        *args = ft_strdup("");
    while (g_minishell.curr_token && g_minishell.curr_token->type == IDENTIFIER)
    {
        to_free = *args;
        *args = ft_strjoin_with(*args, g_minishell.curr_token->value, ' ');
        if (!*args)
            return (free(to_free), false);
        free(to_free);
        ft_get_next_token();
    }
        return (true);
}

t_node *ft_get_simple_cmd(void)
{
    t_node  *node_cmd;
    
    if(g_minishell.parse_err.type)
        return (NULL);  
    node_cmd = ft_new_node(NODE_CMD);
    if(!node_cmd)
        return (ft_set_parse_err(MEM), NULL);
    while (g_minishell.curr_token && (g_minishell.curr_token->type == IDENTIFIER || ft_is_redir(g_minishell.curr_token->type)))
    {
        if(g_minishell.curr_token->type == IDENTIFIER)
        {
            if (!ft_join_args(&node_cmd->args))
                return (ft_clear_cmd(node_cmd), ft_set_parse_err(MEM), NULL);
        }
        else if(ft_is_redir(g_minishell.curr_token->type))
        {
            if (!ft_get_io_list(&node_cmd->io_list))
                return (free(node_cmd->args), free(node_cmd), NULL);
        }
    }
    return (node_cmd);
}