
NAME = libftprintf.a
C_Compiler = cc
CFLAGS = -Wall -Wextra -Werror

Funs = 	ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthexa.c ft_putunsgned.c ft_putadrs.c ft_printf.c

OFuns = $(Funs:.c=.o)

all: $(NAME)

$(NAME): $(OFuns)
	@ar rc ${NAME} $(OFuns)
	
%.o: %.c ft_printf.h
	@$(C_Compiler) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFuns)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean