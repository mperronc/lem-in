# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <mperronc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2017/05/01 17:28:08 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = src/

SRC_NAME =	lemin.c \
			read_map.c \
			parse_map.c \
			make_rooms.c \
			allocate_rooms.c \
			make_tunnels.c \
			make_tunnel.c \
			validate_map.c \
			select_next.c \
			weigh_edges.c \
			weigh_neighbors.c \
			find_path.c \
			find_paths.c \
			filter_paths.c \
			lookup_room.c \
			print_adj_rooms.c \
			print_rooms.c \
			init_rooms.c \
			free_tab.c \
			print_paths.c \
			only_numbers.c \
			free_lemin.c \
			create_ants.c \
			print_ants.c \
			move_ant.c \
			only_one_start_end.c

OBJ_PATH = obj/

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = lem-in

CC = clang
CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
