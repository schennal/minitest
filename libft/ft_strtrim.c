/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:18:15 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:26:54 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	if_present(char c, const char *set)
{
	size_t	t;

	t = 0;
	while (set[t] != '\0')
	{
		if (set[t] == c)
			return (1);
		t++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	size_t	slen;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	slen = ft_strlen(s1);
	while (s1[j] && if_present(s1[j], set))
		j++;
	while (slen > j && if_present(s1[slen - 1], set))
		slen--;
	str = (char *)malloc(sizeof(*s1) * (slen - j + 1));
	if (!str)
		return (NULL);
	while (j < slen)
		str[i++] = s1[j++];
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	char *str = "helloi just want this part hello";
// 	char *ret = ft_strtrim(str, "hello");
// 	printf("substring = %s", ret);
// 	return 0;
// }