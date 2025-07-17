#include "ft.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	n;
	int	m;

	i = 1;
	while (i < argc)
	{
		n = my_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			m = my_atoi(argv[j]);
			if ((n == m) && (i != j))
			{
				write(1, "true", 4);
				return (0);
			}
			j++;
		}
		i++;
	}
	write(1, "false", 5);
	return (1);
}
