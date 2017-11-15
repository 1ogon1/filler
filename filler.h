#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdio.h>// just for check
# include <fcntl.h>// just for check

/*
*				MAIN STRUCTURE FOR FILLER
*/
typedef struct	s_env
{
/*
**				MAP
*/
	int 		map_x;
	int 		map_y;
	char		**map;
/*
**				TOKEN
*/
	int 		token_x;
	int 		token_y;
	char 		**token;
/*
**				RESULT COORDINATE
*/
	int 		x;
	int 		y;
/*
**				OTHER
*/
	char 		exec;
	int 		error;
}				t_env;

/*
**				USED FUNCTION
*/
int				ft_set_token(t_env *e, int i, int j, int is_set);
void			ft_check_line(char *line, t_env *e);
void			ft_write_token(char *line, t_env *e, int i);
void			ft_write_map(char *line, t_env *e, int i, int j);

#endif
