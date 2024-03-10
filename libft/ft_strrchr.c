/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:23:29 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:26:31 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	d;
	char	*ptr;

	j = ft_strlen(s);
	d = (char)c;
	ptr = (char *)s;
	if (d == 0)
	{
		return (&ptr[j]);
	}
	while (j > 0)
	{
		if (ptr[j - 1] == d)
		{
			return (&ptr[j - 1]);
		}
		j--;
	}
	return (0);
}
/*
int main () {
   const char str[] = "hello how are you";
   const char ch = 'o';
   char *ret;
   char *ret1;

   ret = strrchr(str, 'o');
   ret1 = ft_strrchr(str, 'o');

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("string after |%c| is - |%s|\n", ch, ret1);

   return(0);
}
*/
