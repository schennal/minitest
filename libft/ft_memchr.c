/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:54:33 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:20:19 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*str;

	i = 0;
	d = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == d)
			return ((char *)(str + i));
		i++;
	}	
	if (str == 0)
	{
		return (0);
	}
	return (0);
}

// int main()
// {
// 	char src[]= "abc'\0'def";
// 	printf("%s\n",ft_memchr(src, 'e', 9));
// 	printf("%s\n",memchr(src, 'e', 9));
// }