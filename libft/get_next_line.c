#include "libft.h"

static int  ft_str_len_tonl(char *str)
{
    int     len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
    {
        if (str[len] == '\n' || str[len] == '\0')
            break ;
        len++;
    }
    return (len);
}

static char	*ft_write_line(char **str, int i, int j)
{
    char	*res;
	char	*dst;
	char	*test;

	test = *str;
	if (!(res = (char *)malloc(sizeof(char) * (ft_str_len_tonl(*str) + 1))))
		return NULL;
	while (test[i] != '\n')
	{
        res[i] = test[i];
		i++;
	}
	res[i] = '\0';
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(*str) - ft_str_len_tonl(*str)))))
		return NULL;
	i++;
	while (test[i])
		dst[j++] = test[i++];
	dst[j] = '\0';
	free(*str);
	*str = NULL;
	*str = dst;
    return (res);
}

int 	get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0)
		return (-1);
//	if (line)
//		free(*line);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
		if (str != NULL && ft_strrchr(str, '\n'))
		{
			*line = ft_write_line(&str, 0, 0);
			break ;
		}
	}
	if (!str || ret == 0)
		return (0);
	return (1);
}
/*
int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(0, &line)) > 0)
		printf("%s\n", line);
	return 0;
}*/