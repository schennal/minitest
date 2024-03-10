/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:25:07 by schennal          #+#    #+#             */
/*   Updated: 2024/03/10 18:32:54 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXPAND
# define EXPAND
# include <stdbool.h>

/*------expand_hd-----*/
void    expand_heredoc(char *str, int fd);

/*-----expand_str-----*/
char	**str_expander(char const *s);

/*------expand_utils----*/
char	*clr_empty_str(char *str);
bool	ft_is_valid_var_char(char c);
char	*preproc_str(char *str);

/*------expand_utils1----*/
char	**split_str(char const *s, char **strs);
void	next_word(char const *s, size_t	*i);
char	**generate_token(char const *s, char **strs);

/*-----expand-----*/
char	*remove_quotes(char *str);
char    **expand_str(char *str);

/*-----prepoc_str-----*/
char	*extract_squotes(char *str, size_t *i);
char	*extract_dquotes(char *str, size_t *i);
char	*extract_dquote_str(char *str, size_t *i);
char	*extract_dollar(char *str, size_t *i);
char	*handle_str(char *str, size_t *i);





#endif