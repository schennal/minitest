/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:27:41 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:19:46 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	**str_expander(char const *s)
{
    size_t		i;
	size_t		str_num;
    char		**str_array;
	char		**cpy_array;
	
    i = 0;
	str_num = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != ' ' && ++str_num)
			next_word(s, &i);
		while (s[i] && s[i] == ' ')
			i++;
	}
	cpy_array = ft_calloc(str_num + 1, sizeof(char *));
	cpy_array = str_array;
	str_array = split_str(s, cpy_array);
	if (!cpy_array || !str_num)
		return (ft_free_char2(cpy_array), NULL);
	return (generate_token(s, cpy_array));
}
