/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:37:26 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:25:23 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	dstlen = ft_strlen(src);
	return (dstlen);
}

/*
int main()
{
	char src[] = "hi, how are you???";
	char dest[] = "good morning";
	printf("%zu\n",ft_strlcpy(dest,src,30));
	printf("%zu",strlcpy(dest,src,30));
}
*/