#include "get_next_line.h"

int	main()
{
	int fd;
	char *line;

	fd = open("./test", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}