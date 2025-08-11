#include <unistd.h>

void	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	count_to_remove(int *open_rem, int *close_rem, char *str)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	*open_rem = 0;
	*close_rem = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open == 0)
				(*close_rem)++;
			else
				open--;
		}
		i++;
	}
	*open_rem = open;
}

void	generate(int open_rem, int close_rem, int idx, char *str, int bal,
		int res_len, char *out)
{
	if (!str[idx])
	{
		if (open_rem == 0 && close_rem == 0 && bal == 0)
			ft_putstr(out, res_len);
		return ;
	}
	if (str[idx] == '(')
	{
		if (open_rem > 0)
			generate(open_rem - 1, close_rem, idx + 1, str, bal, res_len, out);
		out[res_len] = '(';
		generate(open_rem, close_rem, idx + 1, str, bal + 1, res_len + 1, out);
	}
	else if (str[idx] == ')')
	{
		if (close_rem > 0)
			generate(open_rem, close_rem - 1, idx + 1, str, bal, res_len, out);
		if (bal > 0)
		{
			out[res_len] = ')';
			generate(open_rem, close_rem, idx + 1, str, bal - 1, res_len + 1,
				out);
		}
	}
	else
	{
		out[res_len] = str[idx];
		generate(open_rem, close_rem, idx + 1, str, bal, res_len + 1, out);
	}
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char out[1024];

	if (ac == 2)
	{
		int open_rem = 0;
		int close_rem = 0;
		count_to_remove(&open_rem, &close_rem, av[1]);
		// printf("%d", open_rem);
		generate(open_rem, close_rem, 0, av[1], 0, 0, out);
		return (0);
	}
	else
		write(1, "\n", 1);
	return (0);
}