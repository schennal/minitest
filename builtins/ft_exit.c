/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:12:54 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 17:34:34 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void ft_exit(char **av, t_data **data)
// {
//     // size_t i;

//     // i = 0;
//     (*data)->exit_status = 1;
//     ft_putstr_fd("exit ", STDERR_FILENO);
//     av[1] ? ft_putendl_fd("1", STDERR_FILENO) : ft_putendl_fd("0",
//STDERR_FILENO);
//     if(av[1] && av[2])
//     {
//         (*data)->ret = 1;
//         ft_putendl_fd("TOO MANY ARGUMENTS\n", STDERR_FILENO);
//     }
//     else if(av[1] && ft_isnum(av[1]) == 0)
//     {
//         (*data)->ret = 255;
//         ft_putstr_fd("exit ", STDERR_FILENO);
//         ft_putstr_fd(av[1], STDERR_FILENO);
//         ft_putstr_fd(" NUMERIC ARGUMENT REQUIRED\n", STDERR_FILENO);
//     }
//     else if (av[1])
//         (*data)->ret = ft_atoi(av[1]);
//     else
//         (*data)->ret = 0;

// }

static bool	ft_isnumber(const char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (false);
		s++;
	}
	return (true);
}

static int	ft_exittoi(const char *s)
{
	int	result;

	result = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			if (result > INT_MAX)
			{
				return (-1); // Indicate error
			}
		}
		else
		{
			return (-1); // Indicate error
		}
		s++;
	}
	return (result % 256);
}

void	ft_exit(char **args)
{
	int	exit_s;

	exit_s = 0;
	if (args[1])
	{
		if (args[2] || !ft_isnumber(args[1]))
		{
			exit_s = 1; // Indicate error
		}
		else
		{
			exit_s = ft_exittoi(args[1]);
		}
	}
	exit(exit_s);
}

// int main() {
//     // Initialize a dummy command
//     char *cmd[] = {"exit", "hello", NULL};

//     // Create a mini shell instance
//     t_data mini_shell;
//     t_data *mini_shell_ptr = &mini_shell;
//     mini_shell.exit_status = 0;
//     mini_shell.ret = 0;

//     // Call ft_exit function
//     ft_exit(cmd, &mini_shell_ptr);

//     // Print the exit status
//     printf("Exit status: %d\n", mini_shell.exit_status);
//     printf("Return status: %d\n", mini_shell.ret);

//     return (0);
// }
