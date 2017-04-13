/* 42 header */

#ifndef HEX_H
# define HEX_H

# define NORMAL 0;
# define START 1;
# define END 2;

typedef struct	s_room {
	int			id;
	char		*name;
	int 		x;
	int  		y;
	int			type;
}				t_room;

typedef struct	s_hex {
	int			ants;
	t_room		**rooms;
}				t_hex;

#endif
