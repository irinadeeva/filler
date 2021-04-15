
NAME = bhugo.filler

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

SRC_D = ./src/
SRC =	$(SRC_D)main.c \
		$(SRC_D)parse_board.c \
		$(SRC_D)parse_piece.c \
		$(SRC_D)heatmap.c \
		$(SRC_D)count_coordinate.c \
		$(SRC_D)free_memory.c \
		$(SRC_D)initiation.c


OBJ_D = ./obj/
OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D = ./libft/
LIBFT = $(LIBFT_D)libft.a


INC_D = ./inc/
INC =	-I$(INC_D) \
		-I$(LIBFT_D)

LIB = $(LIBFT)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	mkdir -p $(OBJ_D)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LIBFT_D) clean
	/bin/rm -rf $(OBJ_D);

fclean: clean
	@make -C $(LIBFT_D) fclean
	/bin/rm -rf $(NAME);

re: fclean all
