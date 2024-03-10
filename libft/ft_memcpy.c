/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:45:02 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:20:27 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *) dst;
	src1 = (unsigned char *) src;
	if (dst1 == 0 && src1 == 0)
	{
		return (0);
	}
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
// int main()
// {
// 	char src[] = "copy";
// 	char dest[] = "here";
// 	printf("%s\n", ft_memcpy(dest,src,3));
// 	printf("%s", memcpy(dest,src,3));
// }
