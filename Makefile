# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 21:59:24 by jubaldo           #+#    #+#              #
#    Updated: 2024/02/02 15:05:52 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS		=	srcs/builtins/cd.c 						\
				srcs/builtins/echo.c					\
				srcs/builtins/env.c 					\
				srcs/builtins/exit.c					\
				srcs/builtins/export.c					\
				srcs/builtins/pwd.c						\
				srcs/builtins/unset.c					\
				srcs/env/is_valid_var_name.c			\
				srcs/env/env_var_remove.c				\
				srcs/env/set_env_var.c					\
				srcs/env/get_env_var.c					\
				srcs/exec/execute_builtin.c				\
				srcs/exec/execute_local.c				\
				srcs/exec/execute_path.c				\
				srcs/exec/execute.c						\
				srcs/init/init_cmd.c					\
				srcs/init/init_commands.c				\
				srcs/init/init_data.c					\
				srcs/init/init_parentheses.c			\
				srcs/init/init_redirections.c			\
				srcs/init/init_pipes.c					\

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g

LFLAGS		=	-lreadline

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ ./minishell successfully created! ~~"
			@echo "$$BIBOU"

clean:
			$(RM)
			rm -rf $(OBJS)
			@echo "\033[31m ~~ ./minishell successfully deleted! ~~"
			@echo "$$PQ"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[31m ~~ ./minishell successfully fdeleted! ~~"

re:			fclean all

.PHONY:		all clean fclean re

info: bibou
define BIBOU
           _       _     _          _ _ 
          (_)     (_)   | |        | | |
 _ __ ___  _ _ __  _ ___| |__   ___| | |
| '_ ` _ \| | '_ \| / __| '_ \ / _ \ | |
| | | | | | | | | | \__ \ | | |  __/ | |
|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|
endef
export BIBOU

info: pq
define PQ

 .--""--.___.._
(  <__>  )     `-.
|`--..--'|      <|      cleaning  ....
|       :|       /
|       :|--""-./
`.__  __;' 
    ""
endef
export PQ
