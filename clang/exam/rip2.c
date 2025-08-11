#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	pre_count(char *str, int *open_par, int *close_par, int len)
{
	int	open;
	int	i;

	open = 0;
	*open_par = 0;
	*close_par = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] == '(')
		{
			open++;
		}
		else if (str[i] == ')')
		{
			if (open == 0)
			{
				(*close_par)++;
			}
			else
				open--;
		}
		i++;
	}
	*open_par = open;
}

void	generate(char *in_str, char *output, int in_len, int out_len,
		int open_par, int close_par, int bal, int dep)
{
	if (dep == in_len)
	{
		if (open_par == 0 && close_par == 0 && bal == 0)
		{
			write(1, output, out_len);
			write(1, "\n", 1);
		}
		return ;
	}
	if (in_str[dep] == '(')
	{
		if (open_par > 0)
		{
			generate(in_str, output, in_len, out_len, open_par - 1, close_par,
				bal, dep + 1);
		}
		output[out_len] = in_str[dep];
		generate(in_str, output, in_len, out_len + 1, open_par, close_par, bal
			+ 1, dep + 1);
	}
	else if (in_str[dep] == ')')
	{
		if (bal > 0)
		{
			output[out_len] = in_str[dep];
			generate(in_str, output, in_len, out_len + 1, open_par, close_par,
				bal - 1, dep + 1);
		}
		if (close_par > 0)
		{
			generate(in_str, output, in_len, out_len, open_par, close_par - 1,
				bal, dep + 1);
		}
	}
	else
	{
		output[out_len] = in_str[dep];
		generate(in_str, output, in_len, out_len + 1, open_par, close_par, bal,
			dep + 1);
	}
}

int	main(int ac, char **av)
{
	int		open_par;
	int		close_par;
	int		len;
	char	out[1024];

	if (ac == 2)
	{
		open_par = 0;
		close_par = 0;
		len = ft_strlen(av[1]);
		pre_count(av[1], &open_par, &close_par, len);
		generate(av[1], out, len, 0, open_par, close_par, 0, 0);
	}
	else
		write(1, "\n", 1);
	return (0);
}
