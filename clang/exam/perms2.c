#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort(char *str, char *res, int len)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
}

void	generate(char *str, char *res, bool *used, int dep, int len)
{
	if (dep == len)
	{
		write(1, res, len);
		write(1, "\n", 1);
	}
	for (int i = 0; i < len; i++)
	{
		if (!used[i])
		{
			res[dep] = str[i];
			used[i] = true;
			generate(str, res, used, dep + 1, len);
			used[i] = false;
		}
	}
}

int	main(int ac, char **av)
{
	char	*sorted;
	char	*res;
	int		len;
	bool	*used;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		sorted = malloc((len + 1) * sizeof(char));
		if (!sorted)
			return (EXIT_FAILURE);
		res = malloc((len + 1) * sizeof(char));
		if (!res)
			return (EXIT_FAILURE);
		used = calloc(len, sizeof(bool));
		if (!used)
			return (free(sorted), EXIT_FAILURE);
		sort(av[1], sorted, len);
		generate(sorted, res, used, 0, len);
		free(res);
		free(sorted);
		free(used);
		return (0);
	}
	else
		return (0);
}
