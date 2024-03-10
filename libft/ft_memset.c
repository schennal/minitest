/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:30:27 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:21:26 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*typecast;

	typecast = (char *)b;
	i = 0;
	while (i < len)
	{
		typecast[i] = c;
		i++;
	}
	return (b);
}

// int main()
// {
// 	char src[]= "abcdef";
// 	printf("mine = %s\n",ft_memset(src, '.', 4));
// 	printf("theirs =%s",memset(src, '.', 4));
// }