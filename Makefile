#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes $(LIBFT_INC)
MLXLIB = -lXext -lX11 -lm -lz
LIBMLX = -L./usr/local/lib -lmlx
INCLUDE = -I./usr/local/include
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -l:libft.a

#resource
SRCS = main.c src/ft_error.c src/ft_read_file.c src/ft_render.c \
src/ft_valid_map.c src/ft_extra_fun.c src/ft_find_items.c src/ft_interactive.c
OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFT_DIR = includes
OBJDIR = obj
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBMLX) $(MLXLIB) $(LIBFT_LINK) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)/src

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean

.SECONDARY: $(OBJECTS)
