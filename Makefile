NAME = so_long
FLAGS = -Wall -Werror -Wextra
SRCS = handle_errors.c map_setup.c check_validaty.c clean.c handle_window.c handle_image.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS))
OBJ = $(SRCS:.c=.o)
INC = -I /includes/so_long.h /includes/strucs.h
LIBFT = libft.a
LIBFTSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c \
ft_power_of.c get_next_line.c ft_isspace.c ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c
LIBSRCS = $(addprefix ./libft/, $(LIBFTSRCS))
LIBOBJ = $(LIBSRCS:.c=.o)
LINFLAGS = -lmlx -lXext -lX11
MOSFLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	make -C ./libft
#cc $(FLAGS) $(SRCSDEST) main.c -o $(NAME) -L /usr/local/lib $(MOSFLAGS) -L. ./my_libft/libft.a
	cc $(FLAGS) $(SRCSDEST) main.c -o $(NAME) -L /usr/local/lib $(LINFLAGS) -L. ./libft/libft.a
clean:
	rm -f *.o $(LIBOBJ)

fclean: clean
	rm -f $(NAME) ./libft/$(LIBFT)


make re: fclean all

$(LIBFT):
	make -C ./libft
