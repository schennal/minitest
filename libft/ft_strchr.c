/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:38:37 by schennal          #+#    #+#             */
/*   Updated: 2023/02/15 17:32:26 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}

// int main()
// {
// 	printf("%s\n",ft_strchr("123456789", 54));
// 	printf("%s",strchr("123456789", 54));
// }