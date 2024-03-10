/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:22:25 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:58:17 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_error(char *av)
// {
// 	printf("cd:  %s :", av);
// 	perror(" ");
// }

// int	get_array_len(char **av)//to get the number of commands(strings). if there is more than 2 command then it means there is error
// {
// 	int	len;

// 	len = 0;
// 	while (av[len])
// 		len++;
// 	return (len);
// }

// int	ft_isnum(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL)
// 		return (0);
// 	if (str[0] == '-')
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// size_t	equal_sign(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '=')
// 			return (i + 1);
// 		i++;
// 	}
// 	return (0);
// }

// int	invalid_identifier(char *str, int f)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 	{
// 		if (f && i == (int) equal_sign(str) - 1)
// 			break ;
// 		if (str[i] == '|' || str[i] == '<' || str[i] == '>'
// 			|| str[i] == '[' || str[i] == ']' || str[i] == '='
// 			|| str[i] == '\'' || str[i] == '\"' || str[i] == ' '
// 			|| str[i] == ',' || str[i] == '.' || str[i] == '*'
// 			|| str[i] == ':' || str[i] == '/' || str[i] == '{'
// 			|| str[i] == '^' || str[i] == '%' || str[i] == '#'
// 			|| str[i] == '@' || str[i] == '!' || str[i] == '~'
// 			|| str[i] == '-' || str[i] == '?' || str[i] == '&'
// 			|| str[i] == '}' || str[i] == '+' || str[i] == '$' )
// 			return (1);
// 	}
// 	return (0);
// }

// void	free_array(char ***str)
// {
// 	int	i;

// 	i = -1;
// 	while ((*str)[++i])
// 		free((*str)[i]);
// 	free(*str);
// }

int	ft_check_key(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_extract_key(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (ft_cleanup(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

bool	ft_env_entry_exists(char *key)
{
	t_env	*envlst;

	envlst = g_minishell.env_list;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (true);
		envlst = envlst->next;
	}
	return (false);
}

char	*ft_extract_value(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (ft_cleanup(
					ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

// void	free_array(void **ptr)
// {
// 	int	i;

// 	i = 0;
// 	while (*ptr && ptr && ptr[i])
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	if (ptr)
// 		free(ptr);
// }


