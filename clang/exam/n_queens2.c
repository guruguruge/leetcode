#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	print_res(int *res, int res_len)
{
	for (int i = 0; i < res_len; i++)
	{
		if (i == 0)
			fprintf(stdout, "%d", res[i]);
		fprintf(stdout, " %d", res[i]);
	}
}

bool	is_safe(int *res, int cur_row, int cur_col)
{
	int	prev_row;

	for (int col = 0; col < cur_col; col++)
	{
		prev_row = res[col];
		if (cur_row == prev_row || prev_row + col == cur_row + cur_col
			|| prev_row - col == cur_row - cur_col)
			return (false);
	}
	return (true);
}

void	generate(int num, int res_len, int dep, int *res)
{
	if (dep == num)
	{
		print_res(res, res_len);
		fprintf(stdout, "\n");
	}
	for (int i = 0; i < num; i++)
	{
		if (is_safe(res, i, dep))
		{
			res[dep] = i;
			generate(num, res_len + 1, dep + 1, res);
		}
	}
}

int	main(int ac, char **av)
{
	int	res[1024];
	int	num;

	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 0)
			return (EXIT_SUCCESS);
		else if (num == 2 || num == 3)
			return (EXIT_FAILURE);
		else if (num == 1)
			return (fprintf(stdout, "0\n"), EXIT_SUCCESS);
		else
			generate(num, 0, 0, res);
		return (0);
	}
	else
		return (0);
}
