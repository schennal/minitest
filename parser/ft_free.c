/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:53:51 by pamone            #+#    #+#             */
/*   Updated: 2024/02/21 19:17:02 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ft_free_io_list(t_io **io_list)
{
    t_io    *current_node;
    t_io    *next;

    current_node = *io_list;
    if(!current_node)
        return ;

    while (current_node)
    {
        free(current_node->value);
        next = current_node->next;
        free(current_node);
        current_node = next;
    }
    *io_list = NULL;
}

void    ft_clear_cmd(t_node *cmd)
{
    if(!cmd)
        return ;
    ft_free_io_list(&cmd->io_list);
}
void    ft_recursive_free_ast(t_node *node)
{
    if(!node)
        return ;
    if(node->type == NODE_CMD)
        ft_clear_cmd(node);
    else
    {
        if (node->left)
            ft_recursive_free_ast(node->left);
        if (node->right)
            ft_recursive_free_ast(node->right);
    }
    free(node);
}
void   ft_free_ast(t_node **ast)
{
    if(!ast)
        return ;
    ft_recursive_free_ast(*ast);
    *ast = NULL;
    //ft_free_token(&g_minishell.token_list); this to be modified. 
}