C_Compiler = cc
CFLAGS = -Wall -Wextra -Werror


libftprintf = Funs/libftprintf.a
LIBS = -LFuns -lftprintf

all: server client server_bonus client_bonus
mandatory: server client
bonus: client_bonus server_bonus

server: server.c $(libftprintf)
	@$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

client: client.c $(libftprintf)
	@$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

client_bonus: client_bonus.c $(libftprintf)
	@$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

server_bonus: server_bonus.c $(libftprintf)
	@$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)


$(libftprintf):
	@make -C Funs

clean:
	@rm -f *.o
	@make -C Funs clean

fclean: clean
	@rm -f server client server_bonus client_bonus
	@make -C Funs fclean

re: fclean all

.PHONY: clean 

