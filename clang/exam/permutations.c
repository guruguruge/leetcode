#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*sort(char *str, int len)
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
	return (str);
}

bool	check_dup(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i + 1])
	{
		if (str[i] == str[i + 1])
			return (true);
		i++;
	}
	return (false);
}

void	generate(char *str, char *res, int *used, int i, int len)
{
	int	j;

	if (i == len)
	{
		write(1, res, len);
		write(1, "\n", 1);
		return ;
	}
	j = 0;
	while (j < len)
	{
		if (!used[j])
		{
			used[j] = 1;
			res[i] = str[j];
			generate(str, res, used, i + 1, len);
			used[j] = 0;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int len = ft_strlen(av[1]);

		// puts(av[1]);
		char *sorted = sort(av[1], len);
		// puts(sorted);
		if (!check_dup(sorted, len))
		{
			int *used = calloc(len, sizeof(int));
			if (!used)
				return (1);
			char *result = malloc((len + 1) * sizeof(char));
			if (!result)
				return (free(used), 1);
			generate(sorted, result, used, 0, len);
			free(result);
			free(used);
			return (0);
		}
		else
			return (1);
	}
	else
		return (1);
}