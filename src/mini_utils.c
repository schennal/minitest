/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:39:36 by schennal          #+#    #+#             */
/*   Updated: 2024/03/13 14:50:02 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count_sign(const char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			count = -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

long long	ft_atol(const char *str)
{
	int			sign;
	long long	ans;
	int			i;

	ans = 0;
	sign = ft_count_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return (sign * ans);
}
