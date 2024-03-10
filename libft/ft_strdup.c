/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:43:06 by schennal          #+#    #+#             */
/*   Updated: 2023/02/28 20:58:12 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		slen;
	int		i;
	char	*copy;	

	i = 0;
	slen = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * slen + 1);
	if (!copy)
		return (0);
	while (s1[i] != 0 && i < slen)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[slen] = '\0';
	return (copy);
}

// int main()
// {
// 	char s1[] = "hello how are you";
// 	printf("%s\n", ft_strdup(s1));
// 	printf("%s\n",strdup(s1));

// 	printf("%s\n", ft_strdup(""));
// }