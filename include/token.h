/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:10:27 by schennal          #+#    #+#             */
/*   Updated: 2024/03/07 18:11:11 by schennal         ###   ########.fr       */
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

#endif