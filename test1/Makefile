CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SRC = fractol.c utils.c key_hook.c init.c
NAME = fractol
LIB = -lmlx -lXext -lX11

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "🚀 Building the project..."
	@make -s all -C libft
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a $(LIB) -o $(NAME)
	@echo "✅ Build completed successfully!"


fclean : clean
	@rm -rf $(NAME)
	@make -s fclean -C libft
clean :
	@echo "🧹 Cleaning up..."
	@rm -rf $(OBJ)
	@make -s clean -C libft
	@echo "🗑️  Cleanup done!"

re : fclean all

.PHONY: all clean fclean re
.SECONDARY: