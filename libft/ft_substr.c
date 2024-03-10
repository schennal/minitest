/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:15:06 by schennal          #+#    #+#             */
/*   Updated: 2023/03/07 19:46:51 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = ((char *)malloc((sizeof (char)) * (len + 1)));
	if (!str)
		return (0);
	i = 0;
	while (s[i] != 0 && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int main()
{
	char *str = "hello, how are you???";
	size_t size = 6;
	char *ret = ft_substr(str, 0, size);
	printf("substring is %s\n", ret);
	return 0;
}