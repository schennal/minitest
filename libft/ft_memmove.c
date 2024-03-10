/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:43:49 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:37:13 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*dest;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (!dest && !source)
		return (0);
	if (dest > source)
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char src[] = "copyme";
// 	char dest[] = "here i am";
// 	printf("%s\n", ft_memmove(src,src,6));
// 	printf("%s\n", memmove(src,src,6));
// }