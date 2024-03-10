/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:46:46 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:24:53 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	int		totlen;
	char	*answer;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totlen = s1len + s2len;
	answer = (char *)malloc(sizeof(char) * totlen + 1);
	if (!answer)
		return (0);
	while (s1[i] != 0 && i < s1len)
	{
		answer[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 != 0 && i < s2len && s1len < totlen)
		answer[s1len++] = s2[i++];
	answer[s1len] = '\0';
	return (answer);
}

// int main()
// {
// 	char str1[] = "42";
// 	char str2[] = "AbuDhabi";
// 	printf("%s", ft_strjoin(str1,str2));
// }