#ifndef PARSING
#define PARSING
typedef enum e_type
{
    NODE_PIPE,
    NODE_AND,
    NODE_CMD,
    NODE_OR,
}   t_type;

typedef enum e_io_type
{
    IO_IN,
    IO_OUT,
    IO_APPEND,
    IO_HERE_DOC,
}   t_io_type;

typedef enum e_err_type
{
    MEM = 1,
    SYNTAX,
}   t_err_type;

typedef struct s_io
{
    t_io_type   type;
    char        *value;
    struct s_io *next;
    struct s_io *prev;
}   t_io;

typedef struct s_node
{
    t_type      type;
    t_io        *io_list;
    char        *args;
    t_io        *io;
    struct s_node *left;
    struct s_node *right;
}   t_node;

typedef struct s_parse_error
{
    t_err_type  type;
    char        *msg;
}   t_parse_error;

void    ft_set_parse_err(t_err_type err);
void    ft_handle_parse_err(void);

// ft_free
void    ft_free_io_list(t_io **io_list);
void    ft_clear_cmd(t_node *cmd);
void    ft_recursive_free_ast(t_node *node);
void   ft_free_ast(t_node **ast);

// parser_utils.c
bool    ft_get_io_list(t_io **io_list);
//bool    ft_get_cmd(t_node **cmd);
bool    ft_join_args(char **args);
t_node *ft_get_simple_cmd(void);

// parser_utils_1.c
t_type	ft_get_node_type(t_token_id id);
t_io_type	ft_get_io_type(t_token_id id);
t_node	*ft_new_node(t_type type);
t_io	*ft_new_io(t_token_id type, char *file);
void	ft_append_io_node(t_io **list, t_io *new_io);

// parser_utils_2.c
void    ft_get_next_token(void);
bool ft_is_redir(t_token_id id);
int ft_prec(t_token_id id);
bool    ft_curr_token_is_binop(void);
int ft_curr_token_prec(void);
t_node	*ft_expr(int prec);


// ft_parse.c
t_node	*ft_term(void);
t_node	*ft_term(void);
t_node	*ft_combine(t_token_id op, t_node *left, t_node *right);
t_node	*ft_parse_all(void);
//t_node	*ft_combine(t_token_id op, t_node *left, t_node *right);


#endif
