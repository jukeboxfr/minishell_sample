CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = 	ft_lstcount.c \
		ft_lstevery.c \
		ft_lstfind.c \
		ft_lstsome.c \
		ft_lstpop.c \
		ft_strndup.c \
		ft_putnstr.c \
		ft_strreplace.c \
		ft_atoi.c \
		ft_strindex.c \
		ft_bzero.c \
		ft_str_alpha_cmp.c \
		ft_str_r_alpha_cmp.c \
		ft_strcasecmp.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strsplit.c \
		ft_strrchr.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strnchr.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_tolower.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strccpy.c
OBJS = $(SRCS:.c=.o)
HEADERS = ./includes
CC 	 = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME) $(HEADER)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJS):
	@$(CC) $(CFLAGS) -I$(HEADERS) -c $(SRCS)

clean:
	@rm -Rf $(OBJS)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
