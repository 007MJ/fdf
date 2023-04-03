NAME	= fdf
CFLAG	= -framework Cocoa -framework OpenGL -framework IOKit
USERS	= $(shell whoami)
MLX		= MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USERS)/.brew/opt/glfw/lib/"
CC		= gcc
RM		= rm -rf


SRC		= main.c
OBJ		= $(src:.c=o.c)

%.o : %.c
	$(cc) $(CFLAG) -I$(DIRLIB) -o $@ -c $^

all = $(NAME)

$(NAME) :
	$(CC) $(SRC) $(CFLAG) $(MLX) -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:
	clean all

.PHONY: all, clean, fclean, re
