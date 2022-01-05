#include "get_next_line.h"

int	ft_strlen(char *str, char c)
{
	int i = 0;

	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char *ft_strdup(char *str, char c)
{
	int i = 0;
	char *res;

	if (!(res = malloc(sizeof(char) * ft_strlen(str, c) + 1)))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char *ft_strjoin(char *s1, char *s2, int key)
{
	int i = 0;
	int j = 0;
	char *res;

	if (!s1)
		return (ft_strdup(s2, '\n'));
	if (!s2)
		return (NULL);
	if (*s1 == 0 && *s2 == 0 && key == 1)
	{
		free(s1);
		return (NULL);
	}
	if (!(res = malloc(ft_strlen(s1, 0) + ft_strlen(s2, '\n') + 1)))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = 0;
	free(s1);
	return (res);
}

int	ft_check_n(char *buff)
{
	int i = 0;

	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	reset_buff(char *buff)
{
	int i = 0;
	int j = 0;

	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	while (buff[i])
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	buff[j] = 0;
}

void	ft_bzero(char *str, int size)
{
	int i = 0;

	while (str[i] && i < size)
	{
		str[i] = 0;
		i++;
	}
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char *line;
	int readv;

	if (!(line = ft_strdup("", 0)))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_check_n(buff) == -1)
	{
		if (!(line = ft_strjoin(line, buff, 0)))
			return (NULL);
		ft_bzero(buff, BUFFER_SIZE);
		readv = read(fd, buff, BUFFER_SIZE);
		buff[readv] = 0;
		if (readv <= 0)
		{
			if (!(line = ft_strjoin(line, buff, 1)))
				return (NULL);
			return (line);
		}
	}
	if (!(line = ft_strjoin(line, buff, 0)))
		return (NULL);
	reset_buff(buff);
	return (line);
}