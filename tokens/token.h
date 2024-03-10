/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:41:42 by pamone            #+#    #+#             */
/*   Updated: 2024/02/24 22:37:33 by pamone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN
#define TOKEN
#define PROMPT "minishell$ "
typedef enum  e_token_id
{
    IDENTIFIER,
    INPUT,
    OUTPUT,
    HERE_DOC,
    APPEND_MODE,
    O_PARENT,
    C_PARENT, 
    AND,
    OR,
    NL,
    PIPE,
}   t_token_id;

typedef struct s_token t_token;
typedef char *Value;
struct s_token{
    t_token_id  type;
    Value       value;
    struct  s_token *next;
    struct  s_token *prev;    
};
t_token	*ft_new_token(char *str, t_token_id id_type);
void	ft_append_token(t_token **head, t_token *new_token);
void	ft_free_token(t_token **tokens);
int	ft_append_delimiter(t_token_id id, char **args_line, t_token **token_list);
// int	ft_strncmp(char *string, char *str2, size_t len);
int	ft_isspace(char c);
int ft_skip_spaces(char **line);

// strings.
char	*ft_strjoin_with(char const *s1, char const *s2, char c);
t_token	*ft_handle_tokens(char *line);
t_token	*ft_gen_token(void);
int	ft_append_identifier(char **line_ptr, t_token **token_list);
#endif
