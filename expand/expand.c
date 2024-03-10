/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:44:31 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:29:00 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_strlen_q(char *str)//calcukates the length of unquoted charac
{
	size_t	i;
	size_t	len;
	char	quotes;

	i = 0;
	len = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!quotes)
				quotes = str[i++];
			else if (str[i] == quotes)
				quotes = ((i++) && 0);
			else
				len += (i++ || 1);
		}
		else
				len += (i++ || 1);
	}
	return (len);
}

static void	fill_unquote(char *str, size_t *i, char *ret, size_t *j)
{
	char	quotes;

	quotes = str[(*i)++];
	while (str[*i] != quotes)
		ret[(*j)++] = str[(*i)++];
	(*i)++;
}


char	*remove_quotes(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ret = ft_calloc(1 + ft_strlen_q(str), sizeof(char));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			(fill_unquote(str, &i, ret, &j));
		else
			ret[j++] = str[i++];
	}
	return (free(str), ret);
}


char **expand_str(char *str)
{
    char    **exp_str;//expanded string
    size_t  i;
   
    i = 0;
    str = preproc_str(str);//pre-processsed string
    if(!str)
        return (NULL);
    str = clr_empty_str(str);//removes empty quotes
    if(!str)
        return (NULL);
    exp_str = str_expander(str);
    free(str);
    if(!exp_str)
        return (NULL);
    while(exp_str[i])
    {
        exp_str = remove_quotes(exp_str[i]);
        i++;
    }
    return (exp_str);
}

