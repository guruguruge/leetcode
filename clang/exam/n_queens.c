#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool	is_safe(int num, int *result, int row, int col)
{
	int	prev_row;

	for (int prev_col = 0; prev_col < col; prev_col++)
	{
		prev_row = result[prev_col];
		if (prev_row == row || prev_col + prev_row == col + row || prev_row
			- prev_col == row - col)
			return (false);
	}
	return (true);
}

void	solve(int num, int *result, int col)
{
	if (col == num)
	{
		for (int j = 0; j < num; j++)
		{
			if (j > 0)
				fprintf(stdout, " %d", result[j]);
			else
				fprintf(stdout, "%d", result[j]);
		}
		fprintf(stdout, "\n");
		return ;
	}
	for (int row = 0; row < num; row++)
	{
		if (is_safe(num, result, row, col))
		{
			result[col] = row;
			solve(num, result, col + 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int num = atoi(av[1]);
		if (num == 0)
			return (0);
		else if (num == 2 || num == 3)
			return (1);
		else
		{
			int *result = malloc(((num) * sizeof(int)));
			if (!result)
				return (1);
			solve(num, result, 0);
			free(result);
		}
		return (0);
	}
	else
		return (0);
}