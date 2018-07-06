#include "filler.h"

void	ft_write_map(char *line, t_env *e, int i, int j)
{
	int 	row;

	if (line[3] == ' ')
	{
		if (!e->map)
			if (!(e->map = (char **)malloc(sizeof(char *) * (e->map_y + 1))))
				return ;
		row = ft_atoi(line);
		i += 4;
		if (!(e->map[row] = (char *)malloc(sizeof(char) * (e->map_x + 1))))
			return ;
		while (j < e->map_x)
		{
			e->map[row][j] = line[i];
			i++;
			j++;
		}
		e->map[row][j] = '\0';
		if (row == (e->map_y - 1))
			e->map[row + 1] = 0;
	}
}

void	ft_write_token(char *line, t_env *e, int i)
{
	if (!e->token)
		if (!(e->token = (char **)malloc(sizeof(char *) * (e->token_y + 1))))
			return ;
	if (!(e->token[e->row] = (char *)malloc(sizeof(char) * (e->token_x + 1))))
		return ;
	while (i < e->token_x)
	{
		e->token[e->row][i] = line[i];
		i++;
	}
	e->token[e->row][i] = '\0';
	if (e->row == (e->token_y - 1))
		e->token[e->row + 1] = 0;
    e->row++;
}