/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:13 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:15:43 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = count * size;
	if (size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	ptr = (char *)malloc(j);
	if (!ptr)
	{
		return (0);
	}
	while (i < j)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

// int main()
// {
// 	char *ptr;
// 	char *fptr;
// 	fptr = calloc(3,5);
// 	ptr = ft_calloc(3,5);
// 	printf("%s", ptr);
// 	printf("%s",fptr);
// }