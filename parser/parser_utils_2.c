#include "parsing.h"

void    ft_get_next_token(void)
{
    g_minishell.curr_token = g_minishell.curr_token->next;
}

bool    ft_curr_token_is_binop(void)
{
    t_token_id  id;
    if(g_minishell.curr_token)
        return(false);
    id = g_minishell.curr_token->type;
    if(id == AND || id == OR || id == PIPE)
        return(true);
    return(false);
}
/*
**	Checks if the token is a delimiter

*/
bool ft_is_redir(t_token_id id)
{
    if(id == INPUT || id == OUTPUT || id == APPEND_MODE || id == HERE_DOC)
        return(true);
    return(false);
}
/*
**	Returns the precedence of the token

*/
int ft_prec(t_token_id id)
{
    if(id == OR)
        return(0);
    if(id == AND)
        return(1);
    return(2);
}
/*
**	Returns the precedence of the current token
*/
int ft_curr_token_prec(void)
{
    return(ft_prec(g_minishell.curr_token->type));
}