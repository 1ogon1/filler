#include "filler.h"

static void	ft_null(t_env *e)
{
	e->error = 0;
	e->exec = '\0';
	e->map = NULL;
	e->map_x = 0;
	e->map_y = 0;
	e->token = NULL;
	e->token_x = 0;
	e->token_y = 0;
}

static void	ft_free(t_env *e)
{
	free(e->map);
	free(e->token);
}

int 	main(int argc, char **argv)
{
	char	*line;
	t_env	e;
	int 	fd;// just for check
	int 	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);// just for check
	ft_null(&e);
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_check_line(line, &e);
		free(line);
		i++;
	}
	if (ft_set_token(&e, 0, 0, 0))
		printf("vse ok\nx[%d]:y[%d]", e.x, e.y);
	else
		printf("vse ploho\n");


/*	printf("\nPRINTF TOKEN FROM STRUCT\n\n");
	i = 0;
	while (e.token[i])
	{
		printf("%s\n", e.token[i]);
		i++;
	}*/
	ft_free(&e);
	return (0);
}