/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:58:22 by schennal          #+#    #+#             */
/*   Updated: 2023/02/14 22:15:00 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	answer;

	i = 0;
	sign = 1;
	answer = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		answer = (answer * 10) + (str[i] - '0');
		i++;
	}
	return (answer * sign);
}

/*
int main()
{  
    int val;  
	int val1;
    char string1[20] = "-+47gf25";  
    val = atoi(string1);  
	val1 = ft_atoi(string1);
    printf("String value = %s\n", string1);  
    printf("their Integer value = %d\n", val);  
	printf("mine integer value = %d\n", val1);
    return (0);  
}
*/