/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:26:48 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 17:42:39 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		if (i < (n - 1))
		{			
			i++;
		}
		else
			return (0);
	}
	result = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (result);
}

/*
int	main()
{
	char s1[] = "helloc";
	char s2[] = "gello";
	int	n = 3;
	printf("%d\n",strncmp(s1,s2,4));
	printf("%d",ft_strncmp(s1,s2,4));
}
*/