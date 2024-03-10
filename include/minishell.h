/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/03/07 17:18:17 by schennal          #+#    #+#             */
/*   Updated: 2024/03/07 17:18:17 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "parsing.h"
# include "expand.h" 
# include "token.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef enum e_err_code
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
} t_err_code;

typedef struct s_node
{
	t_type type;
	t_io *io_list;
	char *args;
	char **expanded_args;
	t_io *io;
	struct s_node *left;
	struct s_node *right;
} t_node;

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUI
} t_err_msg;

typedef struct s_err
{
	t_err_code no;
	t_err_msg msg;
	char *cause;
} t_err;

typedef enum e_ast_direction
{
	IN_RD,
	OUT_RD
} t_ast_direction;

typedef struct s_path
{
	t_err err;
	char *path;
} t_path;

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
} t_env;

typedef struct s_exec
{
	char *path;
	char **args;
} t_exec;

typedef struct s_minishell
{
	t_token *tokens;
	t_env *env_list;
	char *line;
	int exit_status;
	int index;
	int stdin;
	int stdout;
	bool sigint; //signint of the child process;
	bool sigint_heredoc;
	t_token *curr_token;
	t_node *ast;
	t_exec exec;
	int in_pipe;
	int in_redirect;
	t_err error_code;
	char *error_file;
	char **environ;
	int last_pid;
	t_parse_error parse_error;
	struct termios og_terminal;
} t_minishell;

extern t_minishell g_minishell;

/* 
envrionment start
char *key; stores the key of the environment variable
char *value; stores the value of the environment variable
struct s_env *next; stores the next environment variable
*/

/*
	int i; stores the index of the command
	int status; stores the status of the command
	int child; stores the child process id
*/

typedef struct s_wait
{
	int i;
	int status;
	int child;
} t_wait;

/*
	char *path; stores the path of the command
	char **args; stores the arguments of the command

*/

/*
	int content; stores the file descriptor
	struct s_fd *next; stores the next file descriptor  
*/
typedef struct s_fd
{
	int content;
	struct s_fd *next;
} t_fd;

/*
	int fd[2]; stores the file descriptor for pipe (interprocess communication)
	where fd[0] is the read end and fd[1] is the write end. 
	struct s_fd *fd_close; stores the file descriptor to close
	struct s_fd *here_doc; stores the file descriptor for heredoc
*/
typedef struct s_context
{
	int fd[2];
	t_fd *fd_close;
	t_fd *here_doc;
} t_context;

typedef enum s_error
{
	SUCESS,
	CMD_NOT_FOUND,
	NO_SUCH_FILE_FILE,
	NO_SUCH_FILE_PROGRAM,
	PERMISSION_DENIED_FILE,
	PERMISSION_DENIED_PROGRAM,
	AMBIGUOUS,
	CD_NO_SUCH_FILE,
	HOME_NOT_SET,
	TOO_MANY_ARGS,
	NUMERIC_REQUI,
} t_error;

/*
	t_list *lst; stores the list of the environment variables
	t_list *tmp; stores the list of the environment variables   
	char quotes; stores the quotes  
	int i; stores the index of the command
*/

typedef struct s_expand
{
	t_list *lst;
	t_list *tmp;
	char quotes;
	int i;
} t_expand;





/*-----dispose-----*/

/*-----env_utils-----*/
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_get_envlst_val(char *key);

/*-----exec_exist-----*/
t_err	ft_check_exec(char *file, bool cmd);
t_err	ft_check_read(char *file);
t_err	ft_check_write(char *file);

/*-----exec_path-----*/
t_path	find_path(char *cmd);
void	ft_free_char2(char **tofree);

/*-----exec_utils-----*/
void	*ft_cleanup(void *ptr, bool clean);
bool	check_delimiter(char *delimiter, char *str);
void	ft_clean_ms(void);

/*-----executor-----*/
int	handle_execution(t_node *tree, bool piped);

/*-----ft_error-----*/
int	put_err_msg(t_err err);

/*-----pipe-----*/
int	handle_pipe(t_node *tree);
int	ft_get_exit_status(int status);

/*-----redirection-----*/
int	ft_append(t_io_node *io_list, int *status);
int	ft_in(t_io_node *io_list, int *status);
int	ft_out(t_io_node *io_list, int *status);

/*-----single_cmd-----*/
int	ft_check_redirection(t_node *node);
void	ft_reset_stds(bool piped);
int	single_cmd(t_node *node, bool piped);

#endif