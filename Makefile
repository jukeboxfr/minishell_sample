# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 18:20:01 by kesaint-          #+#    #+#              #
#    Updated: 2019/06/10 15:07:57 by kesaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
LDIR = libft/
ODIR = obj/
SDIR = srcs/
INCLUDES = -I ./includes -I $(LDIR)includes
CFLAGS = -g -Wall -Werror -Wextra
FILES = main.c minishell.c command.c builtins.c \
		env/clear.c env/handle.c env/parse.c env/str.c \
		builtins/cd.c builtins/echo.c builtins/env.c \
		builtins/setenv.c builtins/unsetenv.c \
		io/read.c io/path.c io/process.c \
		utils/path.c utils/tab.c
SRCS = $(addprefix $(SDIR), $(FILES))
OBJS = $(addprefix $(ODIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L $(LDIR) -lft -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) -c $(FLAGS) $(INCLUDES)  $< -o $@

clean:
	@make -C $(LDIR) / clean
	@rm -rf $(ODIR)

fclean: clean
	@make -C $(LDIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
