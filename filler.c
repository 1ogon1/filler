#include "filler.h"

static void	ft_null(t_env *e)
{
    e->x = 0;
    e->y = 0;
    e->row = 0;
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


	//fd = open(argv[1], O_RDONLY);// just for check

    ft_null(&e);

//    dprintf(2, "%d", e.x);

    while ((get_next_line(0, &line)) > 0)
	{
        //printf("line %s\n", line);
		ft_check_line(line, &e);
		free(line);
        if (e.row == e.token_y && e.row != 0 && e.token_y != 0)
		{
			ft_set_token(&e, 0, 0, 0);
//            int i = 0;
//            while (i < e.map_y)
//            {
//                printf("%s\n", e.map[i]);
//                i++;
//            }
//            i = 0;
//            while (i < e.token_y)
//            {
//                printf("%s\n", e.token[i]);
//                i++;
//            }
			dprintf(1, "%d %d\n", e.x+1, e.y+1);
			ft_free(&e);
			ft_null(&e);
		}
        //fclose(fp);
	}

	return (0);
}