#include <unistd.h>

void	count(char *str, int *open_rem, int *close_rem)
{
	int	open;
	int	i;

	open = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			open++;
		}
		else if (str[i] == ')')
		{
			if (open == 0)
			{
				(*close_rem)++;
			}
			else
				open--;
		}
		i++;
	}
	*open_rem = open;
}

void	generate(int dep, char *str, int bal, char *out, int out_l,
		int open_rem, int close_rem)
{
	if (!str[dep])
	{
		if (bal == 0 && open_rem == 0 && close_rem == 0)
		{
			write(1, out, out_l);
			write(1, "\n", 1);
		}
		return ;
	}
	if (str[dep] == '(')
	{
		if (open_rem > 0)
		{
			generate(dep + 1, str, bal, out, out_l, open_rem - 1, close_rem);
		}
		out[out_l] = str[dep];
		generate(dep + 1, str, bal + 1, out, out_l + 1, open_rem, close_rem);
	}
	else if (str[dep] == ')')
	{
		if (bal > 0)
		{
			out[out_l] = str[dep];
			generate(dep + 1, str, bal - 1, out, out_l + 1, open_rem,
				close_rem);
		}
		if (close_rem > 0)
		{
			generate(dep + 1, str, bal, out, out_l, open_rem, close_rem - 1);
		}
	}
	else
	{
		out[out_l] = str[dep];
		generate(dep + 1, str, bal, out, out_l + 1, open_rem, close_rem);
	}
}

int	main(int ac, char **av)
{
	char out[1000];
	if (ac == 2)
	{
		int open_rem = 0;
		int close_rem = 0;
		count(av[1], &open_rem, &close_rem);
		generate(0, av[1], 0, out, 0, open_rem, close_rem);
		return (0);
	}
	else
		return (0);
}