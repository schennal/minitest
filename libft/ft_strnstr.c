/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:57 by schennal          #+#    #+#             */
/*   Updated: 2023/02/15 19:58:00 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const	char *haystack, const	char *needle, size_t len)
{
	char		*big;
	char		*small;
	size_t		i;
	size_t		j;

	big = (char *)haystack;
	small = (char *)needle;
	if (small[0] == '\0')
		return (big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (small[j] == big[i])
		{
			while (((i + j) < len) && (small[j] == big[i + j]))
			{
				j++;
				if (small[j] == '\0')
					return (&big[i]);
			}			
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char hay[] = "hello how are you ??? ";
// 	char need[] = "are";
// 	printf("%s\n",ft_strnstr(hay, need, 18));
// 	printf("%s",strnstr(hay, need, 18));
// }