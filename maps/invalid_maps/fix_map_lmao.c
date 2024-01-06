/*#include "so_long.h"

int	main(void)
{
	int i;
	int j;

	j = 0;
	int fd;
	fd = open("map2.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("map ain't loading bro\n");
		exit(EXIT_FAILURE);
	}
	char *str;
	char *array[1000];
	while ((str = get_next_line(fd)) != NULL)
	{
		array[i] = ft_strdup(str);
		free(str);
		i++;
	}
	array[i] = NULL;
	for (int k = 0; array[k] != NULL; k++)
		ft_printf("%s", array[k]);
	return (0);
}*/