/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:07:25 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:47:35 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	unset_error(char **av, int i)
// {
// 	int	j;

// 	j = 0;
// 	while (av[++i])
// 	{
// 		if (invalid_identifier(av[1], 0))
// 		{
// 			ft_putstr_fd("unset: `", 2);
// 			ft_putstr_fd(av[i], 2);
// 			ft_putstr_fd("': not a valid identifier\n", 2);
// 			return (1);
// 		}
// 		if (ft_isdigit(av[1][0]))
// 		{
// 			ft_putstr_fd("unset argument starts with digit\n", 2);
// 			return (1);
// 		}
// 		//check "="
// 	}
// 	return (0);
// }

// // void	del_variable(int j, int k, t_data **data)
// // {
// // 	int		i;
// // 	int		len;
// // 	char	**new;

// // 	len = get_array_len((*data)->env);
// // 	new = (char **)ft_calloc(sizeof(char *), len);
// // 	if (!new)
// // 		return ;
// // 	i = -1;
// // 	k = 0;
// // 	while (++i < len)
// // 	{
// // 		if (i != j)
// // 			new[k++] = ft_strdup((*data)->env[i]);
// // 	}
// // 	free_array(&(*data)->env);
// // 	(*data)->env = new;
// // }

// void	del_variable(int j, int k, t_data **data)
// {
// 	int		len;
// 	int		i;
// 	char	**cpy;

// 	len = 0;
// 	while ((*data)->env[len])
// 		len++;
// 	cpy = (char **)ft_calloc(sizeof(char *), (len));
// 	if (!cpy)
// 		return ;
// 	i = -1;
// 	k = 0;
// 	while (++i < len)
// 	{
// 		if (i != j)
// 			cpy[k++] = ft_strdup((*data)->env[i]);
// 	}
// 	free_array(&(*data)->env);
// 	(*data)->env = cpy;
// }

// void	ft_unset(char **av, t_data **data)
// { 
// 	int	i;
// 	int	j;

// 	if (!av[1])
// 		return ;
// 	if (unset_error(av, 0))
// 		return ;
// 	i = 0;
// 	while (av[++i])
// 	{
// 		j = -1;
// 		while ((*data)->env[++j])
// 		{
// 			if (!(ft_strncmp(av[i], (*data)->env[j], ft_strlen(av[i]))))
// 			{
// 				del_variable(j, i, data);
// 				break ;
// 			}
// 		}
// 	}
// }
// #include "minishell.h"

// int	handle_unset_errors(char **arg, int i)
// {
// 	int j;

// 	if (arg[1] == NULL)
// 		return (1);
// 	while (arg[++i])
// 	{
// 		j = -1;
// 		while (arg[i][++j])
// 		{
// 			if (!ft_isalnum(arg[i][j]) && arg[i][j] != '_' && arg[i][j] != '=')
// 			{
// 				fprintf(stderr, "Error: Invalid character '%c' in unset argument\n", arg[i][j]);
// 				return (1);
// 			}
// 		}
// 		if (ft_isdigit(arg[i][0]))
// 		{
// 			fprintf(stderr, "Error: Argument starts with a digit\n");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// void	unset_var(int j, int k, t_data **data)
// {
// 	int		len;
// 	int		i;
// 	char	**cpy;

// 	len = 0;
// 	while ((*data)->env[len])
// 		len++;
// 	cpy = (char **)ft_calloc(sizeof(char *), (len + 1)); // Allocate memory for NULL terminator
// 	if (!cpy)
// 		return ;
// 	i = -1;
// 	k = 0;
// 	while (++i < len)
// 	{
// 		if (i != j)
// 			cpy[k++] = ft_strdup((*data)->env[i]);
// 	}
// 	free_array((void *)(*data)->env); // Free memory of old array without freeing individual strings
// 	(*data)->env = cpy;
// }

// void	ft_unset(char **args, t_data **data)
// {
// 	int	i;
// 	int	j;

// 	if (handle_unset_errors(args, 0))
// 		return ;
// 	i = 0;
// 	while (args[++i])
// 	{
// 		j = -1;
// 		while ((*data)->env[++j])
// 		{
// 			if (!(ft_strncmp(args[i], (*data)->env[j], ft_strlen(args[i]))))
// 			{
// 				unset_var(j, i, data);
// 				break ;
// 			}
// 		}
// 	}
// }


static void	ft_unset_helper(char *key)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = g_minishell.env_list;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				g_minishell.env_list = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(char **args)
{
	int		i;
	bool	err;

	i = 1;
	if (!args[1])
		return (0);
	err = false;
	while (args[i])
	{
		if (!ft_check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = true;
		}
		else
			ft_unset_helper(
				ft_cleanup(ft_extract_key(args[i]), false));
		i++;
	}
	return (err);
}