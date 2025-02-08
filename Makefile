#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes $(LIBFT_INC)
MLXLIB = -lXext -lX11 -lm -lz
LIBMLX = -L./usr/local/lib -lmlx
INCLUDE = -I./usr/local/include
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -l:libft.a

#resource
SRCS = main.c src/keyhook.c src/ft_error.c src/mlx_read_map.c \
src/validmap.c
OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFT_DIR = includes
OBJDIR = obj
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(LIBMLX) $(MLXLIB) $(LIBFT_LINK) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/src

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
