#include "filler.h"

static void	ft_check_player(char *line, t_env *e, int i)
{
	int 	p;

	p = 0;
	while (line[i])
	{
		if (line[i] == 'p')
		{
			if (line[i + 1] == '1')
				p = 1;
			else if (line[i + 1] == '2')
				p = 2;
		}
		if (line[i] == 'f' && line[i + 1] == 'i')
		{
			if (p == 1)
				e->exec = 'X';
			else if (p == 2)
				e->exec = 'O';
			break ;
		}
		i++;
	}
}

static void	ft_create_map(char *line, t_env *e)
{
	int 	look;
	char	*str;

	look = 0;
	str = line;
	while (str)
	{
		if (*str >= '0' && *str <= '9' && look == 0)
		{
			e->map_y = ft_atoi(str);
			look = 1;
			str += ft_numberlen(e->map_y) + 1;
		}
		if (*str >= '0' && *str <= '9' && look == 1)
		{
			e->map_x = ft_atoi(str);
			break ;
		}
		else
			str++;
	}
}

static void	ft_create_token(char *line, t_env *e)
{
	int 	look;
	char	*str;

	look = 0;
	str = line;
	while (str)
	{
		if (*str >= '0' && *str <= '9' && look == 0)
		{
			e->token_y = ft_atoi(str);
			look = 1;
			str += ft_numberlen(e->token_y) + 1;
		}
		if (*str >= '0' && *str <= '9' && look == 1)
		{
			e->token_x = ft_atoi(str);
			break ;
		}
		else
			str++;
	}
}

void			ft_check_line(char *line, t_env *e)
{
	if (ft_strstr(line, "$$$ exec"))
		ft_check_player(line, e, 0);
	else if (ft_strstr(line, "Plateau"))
		ft_create_map(line, e);
	else if (line[0] == '0')
		ft_write_map(line, e, 0, 0);
	else if (ft_strstr(line, "Piece"))
		ft_create_token(line, e);
	else if (line[0] == '.' || line[0] == '*')
		ft_write_token(line, e, 0);
}