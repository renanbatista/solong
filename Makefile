NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include -I./MLX42/include/MLX42
MLX42 = ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS_DIR = ./src
FILES = start windows keypress images utils map move get_next_line_utils get_next_line
OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX42) $(CFLAGS) $(INC) -o $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re