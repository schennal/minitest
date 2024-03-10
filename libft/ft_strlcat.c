/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:12:45 by schennal          #+#    #+#             */
/*   Updated: 2023/02/12 17:41:38 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstl;

	i = 0;
	dstlen = 0;
	if (dst)
		dstlen = ft_strlen(dst);
	dstl = dstlen;
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
	{
		return (srclen + dstsize);
	}	
	while ((src[i] != '\0') && (dstlen + 1 < dstsize))
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dstl + srclen);
}

/*
int main()
{
	char src[10] = "hello";
	char dest[] = "abcd";
	printf("%zu\n",ft_strlcat(dest,src,3));
}
*/