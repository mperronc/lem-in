# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2016/03/23 15:52:51 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = ./src/

SRC_NAME =	lem-in.c \
			parser/read_map.c \
			parser/parse_map.c \
			parser/get_ants.c \
			parser/make_rooms.c \
			parser/allocate_rooms.c \
			parser/make_tunnels.c \
			parser/make_tunnel.c \
			solver/select_next.c \
			solver/weigh_edges.c \
			solver/weigh_neighbors.c \
			solver/find_path.c \
			solver/find_paths.c \
			helpers/lookup_room.c \
			helpers/print_adj_rooms.c \
			helpers/print_rooms.c \
			helpers/init_rooms.c \
			helpers/print_paths.c

OBJ_PATH = ./obj/

INC_PATH = ./incl/

NAME = lemin

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L ./libft -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	make -C ./libft clean
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	make -C ./libft fclean
	rm -fv $(NAME)

re:	fclean all
	make -C ./libft re
