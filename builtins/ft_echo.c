/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:14:54 by schennal          #+#    #+#             */
/*   Updated: 2024/02/23 19:16:49 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_size(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	ft_echo(char **av)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (arg_size(av) > 1)
	{
		while (av[i] && ft_strcmp(av[i], "-n") == 0)
		{
			n_flag = 1;
			i++;
		}
		while (av[i])
		{
			ft_putstr_fd(av[i], 1);
			if (av[i + 1] && av[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}

// int main(void) {
//     // Buffer to store user input
//     char input[1024];

//     // Prompt the user to enter a command
//     printf("Enter a command (echo <text>): ");
//     fgets(input, sizeof(input), stdin);

//     // Parse the user input
//     char *token = strtok(input, " \n");
//     char *args[32]; // Array to store command arguments
//     int arg_count = 0;

//     // Store the parsed tokens in the args array
//     while (token != NULL && arg_count < 31) {
//         args[arg_count++] = token;
//         token = strtok(NULL, " \n");
//     }
//     args[arg_count] = NULL; // Null-terminate the args array

//     // Call ft_echo function with the parsed arguments
//     ft_echo(args);

//     return 0;
// }