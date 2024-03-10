
#include "../minishell.h"
t_token	*ft_gen_token(void)
{
	char	*line;
	t_token	*token_list;

	line = g_minishell.line;
	token_list = ft_handle_tokens(line);
	add_history(line);
	free(line);
	g_minishell.line = NULL;
	return (token_list);
}
