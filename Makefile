#Standard and Directories
NAME	= fractol
MLX		= ./mlx_linux/libmlx_Linux.a
INC		= includes/
SRC_DIR	= sources/
OBJ_DIR	= obj/

#Compiler and Flags
CC		= CC
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

# Source files
SRC		= $(wildcard $(SRC_DIR)*.c)
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#Build rules
all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -L./mlx_linux -l./mlx_linux -L/usr/lib -I./mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I./includes -I/usr/include -I./mlx_linux -O3 -c $< -o $@

clean:
		@$(RM) -r $(OBJ_DIR)

fclean:	clean
		$(RM) $(NAME)

# Phony targets represent actions not files
.PHONY: all clean fclean re
