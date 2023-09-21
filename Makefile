NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include -I./MLX42/include/MLX42
MLX42 = ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS_DIR = ./src
SRCS_DIR_GNL = ./src/gnl
SRCS_DIR_PRINTF = ./src/printf
FILES = initial_window images keypress \
		validate utils start initial_validate_map \
		utils_others flood_fill
FILES_GNL = get_next_line_utils get_next_line
FILES_PRINTF = ft_itoa ft_printf utils

OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(FILES)))
OBJS_GNL = $(addprefix $(SRCS_DIR_GNL)/, $(addsuffix .o, $(FILES_GNL)))
OBJS_PRINTF = $(addprefix $(SRCS_DIR_PRINTF)/, $(addsuffix .o, $(FILES_PRINTF)))

all: $(NAME)

run: re
	./so_long "test_map.ber"

%.o: %.c
	$(CC) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	$(CC) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(MLX42) $(CFLAGS) $(INC) -o $(NAME)

bonus: all

clean:
	$(RM) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re