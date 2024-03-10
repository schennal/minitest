/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:45:12 by schennal          #+#    #+#             */
/*   Updated: 2023/02/10 21:23:46 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*typecast;
	size_t	i;

	i = 0;
	typecast = (char *)s;
	while (i < n)
	{
		typecast[i] = '\0';
		i++;
	}
}

// int main()
// {
// 	char src[]= "abcdef";
// 	ft_bzero(src, 4);
// 	printf("%s",src);
// }
