# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 21:59:24 by jubaldo           #+#    #+#              #
#    Updated: 2024/01/09 12:01:06 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS_DIR	=	./srcs/

SRCS_FILES	=	cd.c echo.c env.c exit.c export.c pwd.c unset.c \
				remove_env_var.c set_env_var.c update_env_var.c \
				exec_builtin.c exec_command.c \
				init_cmd.c init_env.c init_pipes.c init_redirections.c init_tokens.c \
				free_tokens.c parse_tokens.c token_input.c \
				init_minishell.c main.c \
				parse_and_execution.c \
				close_pipes.c create_pipes.c exec_pipes_redrect.c setup_pipe_redir.c \
				append.c heredoc.c input.c output.c redirection_handler.c
				is_cmd_separator.c libft.c libft2.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))	

OBJ_DIR		=	./obj/

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g

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
