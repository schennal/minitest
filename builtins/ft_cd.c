/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:15:37 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 18:00:03 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	return (ft_update_envlst("PWD", cwd, false), 0);
}

static int	ft_cd_home(void)
{
	char	*home;

	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	home = ft_get_envlst_val("HOME");
	if (!home)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	if (chdir(home) == ENO_SUCCESS)
		return (ft_update_envlst("PWD", home, false), 0);
	return (1);
}

static int	ft_cd_err_msg(char *err_msg)
{
	ft_putstr_fd("minishell: cd: `", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
	return (1);
}

int	ft_cd(char *path)
{
	if (!path)
		return (ft_cd_home());
	if (chdir(path) != ENO_SUCCESS)
		return (ft_cd_err_msg(path));
	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	return (ft_change_pwd());
}

// // Function to initialize the environment variables
// void init_env(t_data *data) {
//     // Assume envp is the array of environment variables passed to main
//     extern char **environ;
//     int i = 0;
//     // Count the number of environment variables
//     while (environ[i] != NULL) {
//         i++;
//     }
//     // Allocate memory for the environment variables array
//     data->env = (char **)malloc((i + 1) * sizeof(char *));
//     if (data->env == NULL) {
//         // Handle memory allocation error
//         exit(EXIT_FAILURE);
//     }
//     // Copy the environment variables to the data structure
//     for (int j = 0; j < i; j++) {
//         data->env[j] = strdup(environ[j]);
//         if (data->env[j] == NULL) {
//             // Handle memory allocation error
//             exit(EXIT_FAILURE);
//         }
//     }
//     // Null-terminate the environment variables array
//     data->env[i] = NULL;
// }
// int main() {
//     // Initialize a dummy command
//     char *cmd1[] = {"cd", NULL}; // No argument
//     char *cmd2[] = {"cd", "-", NULL}; // With "-" argument
//     char *cmd3[] = {"cd", "/usr/bin", NULL}; // With directory argument

//     // Create a data structure instance
//     t_data mini_shell;

//     init_env(&mini_shell);
//     mini_shell.command_count = 0;
//     mini_shell.exit_status = 0;
//     mini_shell.ret = 0;
//     mini_shell.input_fd = 0;
//     mini_shell.count_pipes = 0;
//     mini_shell.input = NULL;
//     mini_shell.env = NULL;
//     mini_shell.command = NULL;

//     t_data *mini_shell_ptr = &mini_shell;

//     // Test cases
//     printf("Testing cd with no argument:\n");
//     ft_cd(cmd1, &mini_shell_ptr);
//     printf("\n");

//     printf("Testing cd with \"-\" argument:\n");
//     ft_cd(cmd2, &mini_shell_ptr);
//     printf("\n");

//     printf("Testing cd with directory argument:\n");
//     ft_cd(cmd3, &mini_shell_ptr);
//     printf("\n");

//     return 0;
// }