C_Compiler = cc
CFLAGS = -Wall -Wextra -Werror


libftprintf = Funs/libftprintf.a
LIBS = -LFuns -lftprintf

all: server client

server: server.c $(libftprintf)
	$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

client: client.c $(libftprintf)
	$(C_Compiler) $(CFLAGS) -o $@ $< $(LIBS)

$(libftprintf):
	make -C Funs

clean:
	rm -f *.o
	make -C Funs clean

fclean: clean
	rm -f server client 
	make -C Funs fclean

re: fclean all

.PHONY: clean 
