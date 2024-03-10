/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strins_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:03:03 by pamone            #+#    #+#             */
/*   Updated: 2024/02/22 05:11:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

// int	ft_strncmp(char *string, char *str2, size_t len)
// {
	// while (*string == *str2 && *string != '\0' && len > 0) {
		// str2++;
		// string++;
	// }
	// if(len == 0)
		// return (0);
	// return (*string - *str2);
// }
// 


/**
	"if (!c || !ft_strlen(s1) || !ft_strlen(s2))":
		to check if to use the joining char or NOT
*/

char	*ft_strjoin_with(char const *s1, char const *s2, char c)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
		return (ft_strjoin(s1, s2));
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	joined = ft_calloc(total_length, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = c;
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (joined);
}

