# Name
NAME	= fractol

# Compiler and Flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Minilibx
ifeq ($(shell uname),Linux)
	MLX_DIR = minilibx/
	LIBS = -lXext -lX11 -lm
else
	MLX_DIR = minilibx/
	LIBS = -framework OpenGL -framework AppKit
endif
MLX_NAME	= libmlx.a
MLX			= $(MLX_DIR)$(MLX_NAME)

# Libft
LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

# Includes
INC	=	-I ./includes/\
		-I ./libft/\
		-I $(MLX_DIR)

# Source files
SRC_DIR	=	sources/
SRC		=	main.c \
			init.c \
			info.c \
			utils.c \
			fractals.c \
			render.c \
			event.c \
			event_utils.c
SRCS	=	$(addprefix $(SRC_DIRC), $(SRC))

# Object files
OBJ_DIR	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ))

# Build rules
all:			$(MLX) $(LIBFT) $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS):		$(OBJ_DIR)

$(OBJ_DIR):
				@mkdir $(OBJ_DIR)

$(MLX):
				@echo "Making Minilibx..."
				@make -sC $(MLX_DIR)

$(LIBFT):
				@echo "Making Libft..."
				@make -sC $(LIBFT_DIR)


$(NAME):		$(OBJS)
				@echo "Compiling Fractol..."
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(LIBS)
				@echo "Fractol ready."

clean:
				@echo "Removing .o object files..."
				@rm -rf $(OBJ_DIR)
				@make clean -C $(MLX_DIR)
				@make clean -C $(LIBFT_DIR)

fclean:			clean
				@echo "Removing Fractol..."
				@rm -f $(NAME)
				@rm -f $(LIBFT_DIR)$(LIBFT_NAME)

re:		fclean all

# Phony targets represent actions not files
.PHONY: all clean fclean re
