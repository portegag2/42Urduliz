NAME = programa

CC = gcc
#CFLAGS = -Wall -Wextra -Werror

# Archivos fuente - encuentra todos los .c automáticamente
SRCS = main.c $(shell find . -name "*.c" -not -path "./main.c" -type f)

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
#norm:
#	norminette -R CheckForbiddenSourceHeader $(SRCS) *.h

.PHONY: clean fclean re norm
