NAME = programa

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente específicos
SRCS = main.c C-00-dev1/main_00.c C-01-dev/main_01.c C-02-dev/main_02.c $(wildcard C-*/ex*/ft_*.c)

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Regla principal
$(NAME): norm $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)

# Limpiar todo
fclean: clean
	rm -f $(NAME)

# Recompilar todo
re: fclean $(NAME)

# Verificar norminette
norm:
#	norminette -R CheckForbiddenSourceHeader $(SRCS) *.h

.PHONY: clean fclean re norm
