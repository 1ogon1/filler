#include "filler.h"

static int 	ft_check_place(t_env *e, int i, int j)
{
	int	tmp;
	int x;
	int y;
	int count;
	int blya;

	tmp = j;
	y = 0;
	count = 0;
	blya = 0;
	while (e->map[i] && y < e->token_y)
	{
		j = tmp;
		x = 0;
		while (x < e->token_x)
		{
			if (e->token[y][x] == '.' && e->map[i][j] != '.')
				return (0);
			if (e->token[y][x] == '*' && e->map[i][j] == e->exec)
				count++;
			if (!e->map[i][j])
				count = 0;
			j++;
			x++;
			blya++;
		}
		y++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int			ft_set_token(t_env *e, int i, int j, int is_set)
{
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
//			e->x = j;
//			e->y = i;
            e->x = i;
            e->y = j;
			if (ft_check_place(e, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}