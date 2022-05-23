NAME = printf.a

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCLUDES = ./includes/

SRCS =  $(addprefix $(PATH_SRCS),\
		ft_printf.c\
		ft_strlen.c\
		ft_strchr.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_puthexa.c\
		ft_intlen.c\
		ft_read_text.c\
		ft_search_arg.c)
OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I $(PATH_INCLUDES)

MAKELIB = ar rcs
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKELIB) $(NAME) $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(REMOVE) $(PATH_OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

test: re
	@cc main.c printf.a -o test
	clear
	./test

tclean: fclean
	@$(REMOVE) test

.PHONY: all clean fclean re test