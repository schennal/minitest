/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:57 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 20:14:24 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i ;
	int				len;
	char			*answer;

	if (!s || !f)
	{
		return (NULL);
	}
	i = 0;
	len = ft_strlen(s);
	answer = (char *)malloc(sizeof(char) * len + 1);
	if (!answer)
		return (NULL);
	while (s[i] != '\0')
	{
		answer[i] = f(i, s[i]);
		i++;
	}
	answer[i] = '\0';
	return (answer);
}

/*
char ft_func(unsigned int i, char str)
{
    printf("Position : character  = %d and %c\n", i, str);
    return str;
}

int main()
{
	char str[15] = "42AbuDhabi.";
	char *result = ft_strmapi(str, ft_func);
	return 0;
}
*/