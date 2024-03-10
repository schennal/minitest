/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:42:09 by schennal          #+#    #+#             */
/*   Updated: 2024/03/07 20:07:43 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSING
# define PARSING

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



typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}	t_io_node;




typedef struct s_parse_error
{
    t_err_type  type;
    char        *msg;
}   t_parse_error;

#endif