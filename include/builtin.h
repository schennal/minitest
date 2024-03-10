/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:40:57 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 13:50:20 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
#define BUILTIN_H
#include <stddef.h>


#define STDERR 2
#define BUFFER_SIZE 4096
# define READLINE_MSG	"\e[38;5;212mminishell\033[34m$ \033[0m"

typedef struct s_command
{
    struct s_command *next;
    char *name;
    
}   t_command;

typedef struct s_env
{
    char            *name;
    char            *value;
    struct s_env	*next;
}	t_env;


typedef struct s_data
{
    int command_count;
    int exit_status;
    int ret;
    int input_fd;
    int fd_status;
    int stdin;
    int stdout;
    int count_pipes;
    char *input;
    char *path;
    char *new_input;
    char **env;
    
    //t_env *envi;
    t_command *command;
    
    
}   t_data;

int g_exit_status;

int ft_echo(char **av);
int	ft_strcmp(const char *s1, const char *s2);

void	ft_cd(char **av, t_data **data);

/*-----built_utils.c-----*/
int	get_array_len(char **av);
void	print_error(char *av);
int	ft_isnum(const char *str);
size_t	equal_sign(char *str);
int	invalid_identifier(char *str, int f);
void	free_array(char ***str);


void ft_exit(char **av, t_data **data);

void ft_env(char **av, t_data **data);

void ft_pwd(void);

void	ft_unset(char **av, t_data **data);


/*------shlvl-----*/
void	shlvl_increment(t_data **data);




/*-----utils-----*/

int	is_builtin(char *command);


#endif