/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:20:42 by schennal          #+#    #+#             */
/*   Updated: 2023/02/15 19:37:35 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static size_t	ft_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**answer;

	if (!s)
		return (NULL);
	answer = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!answer)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			answer[i++] = ft_substr(s, 0, ft_length(s, c));
			s = s + ft_length(s, c);
		}
	}
	answer[i] = NULL;
	return (answer);
}

int	main()
{
 	char	 **tab;
 	unsigned int	i; 
 	i = 0;
 	tab = ft_split("Hello how are you ? ? ?", ' ');
 	if (!tab[0])
 		ft_putendl_fd("ok\n", 1);
 	while (tab[i] != NULL)
 	{
 		ft_putendl_fd(tab[i], 1);
 		i++;
 	}
}