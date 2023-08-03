CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L./minilibx -lmlx -lXext -lX11
RM = rm -f
INC = -I./include
SRCS_DIR = ./src
FILES = $(SRCS_DIR)/so_long.c
OBJS = $(FILES:.c=.o)

all:
	$(CC) $(CFLAGS) $(FILES) $(INC) $(MFLAGS) -o so_long

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re