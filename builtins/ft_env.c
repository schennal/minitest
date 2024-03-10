/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:43:03 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:43:26 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_env(char **av, t_data **data)
// {
// 	int	i;
// 	int	flag;

// 	if (av[1] != NULL)
// 	{
// 		flag = 0;
// 		if (((av[1][0] == '\"' && av[1][ft_strlen(av[1]) - 1] == '\"')
// 				|| (av[1][0] == '\'' && av[1][ft_strlen(av[1]) - 1] == '\'')))
// 		{
// 			av[1] = ft_substr(av[1], 1, ft_strlen(av[1] - 2));
// 			flag = 1;
// 		}
// 		ft_putstr_fd("env: ", 2);
// 		ft_putstr_fd(av[1], 2);
// 		ft_putstr_fd(": No such file or directory\n", 2);
// 		if (flag)
// 			free(av[1]);
// 	}
// 	i = -1;
// 	while ((*data)->env[++i])
// 	{
// 		if (ft_strchr((*data)->env[i], '='))
// 			printf("%s\n", (*data)->env[i]);
// 	}
// }

// void	print_error2(char *s1, char *s2, char *s3)
// {
// 	int	flag;

// 	flag = 0;
// 	if ((s2[0] == '\"' && s2[ft_strlen(s2) - 1] == '\"')
// 		|| (s2[0] == '\'' && s2[ft_strlen(s2) - 1] == '\''))
// 	{
// 		s2 = ft_substr(s2, 1, ft_strlen(s2) - 2);
// 		flag = 1;
// 	}
// 	ft_putstr_fd(s1, 2);
// 	ft_putstr_fd(s2, 2);
// 	ft_putstr_fd(s3, 2);
// 	if (flag)
// 		free(s2);
// }

// int main(void)
// {
//     // Initialize environment variables for testing
//     char *env[] = {"USER=John", "PATH=/usr/bin", "SHELL=/bin/bash", NULL};

//     // Initialize data structure
//     t_data *data = malloc(sizeof(t_data)); // Allocate memory for t_data
//     if (data == NULL)
//     {
//         fprintf(stderr, "Memory allocation failed\n");
//         return (1);
//     }
//     data->env = env;
//     data->exit_status = 0;

//     // Test ft_env function
//     char *arg[] = {"env", NULL};
//     ft_env(arg, &data);

//     // Free allocated memory
//     free(data);

//     return (0);
// }

/*----------------------------------------------------------------------*/



// Function to retrieve the value of a specific environment variable
static char *get_env_value(t_env *env_list, char *key) {
    t_env *env = env_list;
    while (env != NULL) {
        if (strcmp(env->key, key) == 0) {
            return env->value;
        }
        env = env->next;
    }
    return NULL; // Return NULL if the key is not found
}

// Function to print all environment variables
static void print_all_env(t_minishell *minishell) {
    t_env *env = minishell->env_list;
    while (env != NULL) {
        printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}

// Function to print a specific environment variable
static void print_specific_env(t_minishell *minishell, char *key) {
    char *value = get_env_value(minishell->env_list, key);
    if (value != NULL) {
        printf("%s\n", value);
    } else {
        fprintf(stderr, "env: %s: No such file or directory\n", key);
    }
}

// Main env function
void ft_env(t_minishell *minishell, char **args) {
    if (args[1] == NULL) {
        print_all_env(minishell);
    } else {
        for (int i = 1; args[i] != NULL; i++) {
            print_specific_env(minishell, args[i]);
        }
    }
}