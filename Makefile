NAME = libftprintf.a
NAME_BONUS = libftprintf_bonus.a

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCLUDES = ./includes/
PATH_SRCS_BONUS = ./b_sources/
PATH_OBJS_BONUS = ./b_objects/
PATH_INCLUDES_BONUS = ./b_includes/

SRCS =  $(addprefix $(PATH_SRCS),\
		ft_printf.c\
		ft_strlen.c\
		ft_putbase.c\
		ft_countdigits.c\
		ft_validation.c\
		ft_arg_c.c\
		ft_arg_p.c\
		ft_arg_sdi.c\
		ft_arg_ux.c\
		ft_putchar.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I $(PATH_INCLUDES)

SRCS_BONUS = $(addprefix $(PATH_SRCS_BONUS),\
		ft_printf_bonus.c\
		ft_strlen_bonus.c\
		ft_putbase_bonus.c\
		ft_countdigits_bonus.c\
		ft_validation_bonus.c\
		ft_arg_c_bonus.c\
		ft_arg_p_bonus.c\
		ft_arg_s_bonus.c\
		ft_arg_udi_bonus.c\
		ft_arg_x_bonus.c\
		ft_putchar_bonus.c\
		ft_bzero_bonus.c\
		ft_checkflags_bonus.c\
		ft_isdigit_bonus.c\
		ft_substr_bonus.c\
		ft_freethis_bonus.c)

OBJS_BONUS = $(patsubst $(PATH_SRCS_BONUS)%.c, $(PATH_OBJS_BONUS)%.o, $(SRCS_BONUS))

INCLUDES_BONUS = -I $(PATH_INCLUDES_BONUS)

MAKELIB = ar rcs
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKELIB) $(NAME) $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(REMOVE) $(PATH_OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKELIB) $(NAME_BONUS) $(OBJS_BONUS)
	cp $(NAME_BONUS) $(NAME)

$(PATH_OBJS_BONUS)%.o: $(PATH_SRCS_BONUS)%.c
	mkdir -p $(PATH_OBJS_BONUS)
	cc $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

bclean: fclean
	$(REMOVE) $(PATH_OBJS_BONUS)
	$(REMOVE) $(NAME_BONUS)

test: bclean bonus
	cc $(CFLAGS) -g main.c $(NAME_BONUS) -o test
	./test

tclean: bclean
	$(REMOVE) test

.PHONY: all clean fclean re test tclean