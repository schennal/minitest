/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:10:17 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 21:02:52 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// char ft_func(unsigned int i, char str)
// {
//     printf("Position : character  = %d and %c\n", i, str);
//     return str;
// }

// int main()
// {
// 	char str[15] = "42AbuDhabi.";
// 	char *result = ft_striteri(str, ft_func);
// 	return 0;
// }