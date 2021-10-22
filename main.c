#include "get_next_line.h"

int	main()
{
	int			fd;
	char		*str;
	//int			r;
	int			i;
	i = 0;
	fd = open("lotr.txt", O_RDONLY);
/* 	get_next_line(fd, &str);
	printf("%s", str); */
	while ((str = get_next_line(fd)))
	{
		printf("line %i=>%s\n", i + 1, str);
		free(str);
		i++;
	}
	// printf("%s\n", str);
	// system("leaks a.out");
	return (0);
}
