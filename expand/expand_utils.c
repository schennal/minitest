/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:09:43 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 18:29:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clr_empty_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;
	size_t	dstsize;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2])
		|| (str[0] == '"' && str[1] == '"' && !str[2]))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i + 1] == '\'')
			|| (str[i] == '"' && str[i + 1] == '"'))
			i += 2;
		else
			tmp[j++] = str[i++];
	}
	free(str);
	dstsize = ft_strlen(tmp) + 1;
	ret = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(ret, tmp, dstsize), free(tmp), ret);
}

bool	ft_is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

char	*preproc_str(char *str)
{
	char *ret;
	size_t i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_f(ret, extract_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_f(ret, extract_dquotes(str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_f(ret, extract_dollar(str, &i));
		else
			ret = ft_strjoin_f(ret, handle_str(str, &i));
	}
	return (ret);
}