#include "parsing.h"

t_node	*ft_term(void)
{
	t_node  *node;

	if(g_minishell.parse_err.type)
		return (NULL);
	if(ft_curr_token_is_binop() || g_minishell.curr_token->type == C_PARENT)
		return (ft_set_parse_err(SYNTAX), NULL);
	else if(g_minishell.curr_token->type == O_PARENT)
	{
		ft_get_next_token();
		node = ft_expr(0);
		if(!node)
			return (ft_set_parse_err(MEM), NULL);
		if(!g_minishell.curr_token || g_minishell.curr_token->type != C_PARENT)
			return (ft_set_parse_err(SYNTAX), node);
		ft_get_next_token();
		return (node);
	}
	else
		return(ft_get_simple_cmd());
}
t_node	*

ft_expr(int prec)
{
	t_node	*left;
	t_node	*right;
	int		node_prec;
	t_token_id	op;

	if(g_minishell.parse_err.type || !g_minishell.curr_token)
		return (NULL);
	left = ft_term();
	if(!left)
		return (NULL);
	while(ft_curr_token_is_binop() && ft_curr_token_prec() >= prec)
	{
		op = g_minishell.curr_token->type;
		ft_get_next_token();
		if(!g_minishell.curr_token)
			return (ft_set_parse_err(SYNTAX), left);
		node_prec = ft_prec(op) + 1;
		right = ft_expr(node_prec);
		if(!right)
			return (left);
		left = ft_combine(op, left, right);
		if(!left)
			return (ft_free_ast(&left), ft_free_ast(&right), NULL);
	}
	return (left);
}
t_node	*ft_combine(t_token_id op, t_node *left, t_node *right)
{
	t_node	*node;

	if(g_minishell.parse_err.type)
		return (NULL);
	node = ft_new_node(ft_get_node_type(op));
	if(!node)
		return (NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*ft_parse_all(void)
{
	t_node	*ast;

	g_minishell.curr_token = g_minishell.tokens;
	ast = ft_expr(0);
	if(g_minishell.parse_err.type)
		return (ft_free_ast(&ast), NULL);
	return (ast);
}