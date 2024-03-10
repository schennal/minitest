# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schennal <schennal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 19:55:09 by schennal          #+#    #+#              #
#    Updated: 2024/03/10 14:23:55 by schennal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "libft"

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra

# BUILTINS	:=	builtins/cd.c \
# 				builtins/echo.c \
# 				builtins/env_utils.c \
# 				builtins/env.c \
# 				builtins/exit.c \
# 				builtins/export.c \
# 				builtins/pwd.c \
# 				builtins/unset.c

# CLEANING	:=	cleaning/ft_clean_ms.c

# EXEC		:=	exec/error_msg.c \
# 				exec/exec_builtin.c \
# 				exec/exec_redirect.c \
# 				exec/exec_utils.c \
# 				exec/exec.c \
# 				exec/exist_check.c \
# 				exec/ft_exec_simple_cmd.c \
# 				exec/ft_get_path.c \
# 				exec/init_tree.c

# EXPANDER	:=	expander/ft_asterisker.c \
# 				expander/ft_clean_empty_strs.c \
# 				expander/ft_expand_utils.c \
# 				expander/ft_expand.c \
# 				expander/ft_expander_split.c \
# 				expander/ft_globber_utils.c \
# 				expander/ft_globber.c \
# 				expander/ft_strip_quotes.c \
# 				expander/heredoc_expander.c

# PARSING		:=	parsing/parser_clear.c \
# 				parsing/parser_err.c \
# 				parsing/parser_helpers.c \
# 				parsing/parser_nodes.c \
# 				parsing/parser_utils.c \
# 				parsing/parser.c

# TOKENIZING	:=	tokenizing/tokenizer_appenders.c \
# 				tokenizing/tokenizer_handlers.c \
# 				tokenizing/tokenizer_lst.c \
# 				tokenizing/tokenizer_utils.c \
# 				tokenizing/tokenizer.c

SRCS		:=	\
				dispose.c \
				env_utils.c \
				exec_exist.c \
				exec_path.c \
				exec_utils.c \
				executor.c \
				ft_error.c \
				pipe.c \
				redirection.c \
				single_cmd.c \
				

OBJS		:=	$(SRCS:.c=.o)

READLINE_PATH:=	/goinfre/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline

	@echo "\n"
	@echo "\033[1;36m _    _   ___    _  _   ___    ___    _  _   ___   _      _\033[0m"
	@echo "\033[1;36m|  \/  | |_ _|  | \| | |_ _|  / __|  | || | | __| | |    | | \033[0m"
	@echo "\033[1;36m| |\/| |  | |   | .\` |  | |   \__ \  | __ | | _|  | |__  | |__\033[0m"
	@echo "\033[1;36m|_|  |_| |___|  |_|\_| |___|  |___/  |_||_| |___| |____| |____|\033[0m"
	

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
