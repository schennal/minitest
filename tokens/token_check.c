/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:49:47 by codespace         #+#    #+#             */
/*   Updated: 2024/02/24 22:50:20 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	ft_check_case(char **line_ptr, t_token **token_list)
{
    if (!ft_strncmp(*line_ptr, "&&", 2))
		return (ft_append_delimiter(AND, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "<<", 2))
		return (ft_append_delimiter(HERE_DOC, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ">>", 2))
		return (ft_append_delimiter(APPEND_MODE, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "<", 2))
		return (ft_append_delimiter(INPUT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ">", 2))
		return (ft_append_delimiter(OUTPUT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "(", 2))
		return (ft_append_delimiter(O_PARENT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ")", 2))
		return (ft_append_delimiter(C_PARENT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "||", 2))
		return (ft_append_delimiter(OR, line_ptr, token_list) && 1);
	else 
		return (ft_append_delimiter(PIPE, line_ptr, token_list) && 1);
}
/*
explain me:
1. ft_handle_tokens is called from ft_gen_token
2. ft_handle_tokens is a function that takes a string as an argument and returns a pointer to a token

*/
t_token	*(t)ft_handle_tokens(char *line)
{
	int			error;
	t_token		*token_list;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if(error)
			return (ft_free_token(&token_list), NULL);
		if(ft_isspace(*line))
			ft_skip_spaces(&line);
		else if(!ft_strncmp(line, "&&", 2) || !ft_strncmp(line, "|", 2)
			|| !ft_strncmp(line, ">", 2) || !ft_strncmp(line, "<", 2)
			|| !ft_strncmp(line, "(", 2) || !ft_strncmp(line, ")", 2))
			error = (!ft_check_case(&line, &token_list)&& 1);
		else 
			error = ((!ft_append_identifier(&line, &token_list) && 1));
	}
	return (token_list);
}