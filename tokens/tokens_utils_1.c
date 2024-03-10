/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:11:13 by pamone            #+#    #+#             */
/*   Updated: 2024/02/24 23:18:04 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <time.h>
#include <stddef.h> 
int	ft_is_seperator(char *s)
{
	if (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t'
			|| *s == '<' || *s == '|' || *s == '(' || *s == ')')
			return (1);
	return (0);
}

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}
// function to print quote error
//	int	ft_print_quote_error(char c)
int ft_print_quote_error(char c)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	//g.minishell_status.exit = 258;
	return (0);
}
// function to skip quotes
// int	ft_skip_quotes(char *line, size_t *i)
int	ft_skip_quotes(char *s, size_t *i)
{
	char	quote;

	quote = s[*i];
	(*i)++;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (!s[*i])
		return (0);
	return (1);
}
int	ft_isspace(char c)
{
	return (c >= 9 && c  <= 13) || c == 32;
	
} 
int ft_skip_spaces(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
	return (1);
}
// funtion to skip quotes
// int	ft_skip_quotes(char *line, size_t *i)
// {
// 	char	quote;

// 	quote = line[*i];
// 	if(ft_strchr(line + *i + 1, quote))
// 	{
// 		(*i)++;
// 		while (line[*i] && line[*i] != quote)
// 			(*i)++;
// 		(*i)++;
// 		return (1);
// 	}
// 	return (0);
// }
int	ft_append_delimiter(t_token_id id, char **args_line, t_token **token_list)
{
	t_token *token;

	token = ft_new_token(NULL, id);
	if (!token)
		return (0);
	ft_append_token(token_list, token);
	(*args_line)++;
	if (id == INPUT || id == OUTPUT || id == OR || id == AND)
		(*args_line)++;
	return (1);
}

int	ft_append_identifier(char **line_ptr, t_token **token_list)
{
	char	*temp;
	char	*value;
	t_token	*token;
	size_t	i;

	temp = *line_ptr;
	i = 0;
	while (temp[i] && !ft_is_seperator(temp + i))
	{
		if (ft_is_quote(temp[i]))
		{
			if (!ft_skip_quotes(temp, &i))
				return (ft_print_quote_error(temp[i]), 0);
		}
		else
			i++;
		value = ft_substr(temp, 0, i);
		if (!value)
			return (0);
		token = ft_new_token(value, IDENTIFIER);
		if (!token)
			return (free(value), 0);
		*line_ptr += i;
		return (ft_append_token(token_list, token), 1);
	}
}