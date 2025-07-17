#include "ft.h"

char	*find_nums_cols(char **board, int row)
{
	char	*result;
	int		col;
	int		m;

	result = (char *)malloc(10 * sizeof(char));
	col = 0;
	m = 0;
	if (!result)
		return (NULL);
	my_memset(result, 0, 9);
	result[9] = '\0';
	while (col < 9 && board[row][col] != '\0')
	{
		if (board[row][col] != '.' && board[row][col] >= '0'
			&& board[row][col] <= '9')
			result[m++] = board[row][col];
		col++;
	}
	result[m] = '\0';
	return (result);
}

char	*find_nums_rows(char **board, int col)
{
	char	*result;
	int		row;
	int		m;

	result = (char *)malloc(10 * sizeof(char));
	row = 0;
	m = 0;
	if (!result)
		return (NULL);
	my_memset(result, 0, 9);
	result[9] = '\0';
	while (row < 9 && board[row][col] != '\0')
	{
		if (board[row][col] != '.' && board[row][col] >= '0'
			&& board[row][col] <= '9')
			result[m++] = board[row][col];
		row++;
	}
	result[m] = '\0';
	return (result);
}

int	valid_array(char *nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i] != '\0')
	{
		j = i + 1;
		while (nums[j] != '\0')
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_cols(char **board, int i)
{
	char	*nums;

	nums = find_nums_cols(board, i);
	if (valid_array(nums))
	{
		free(nums);
		return (1);
	}
	free(nums);
	return (0);
}

int	valid_rows(char **board, int j)
{
	char	*nums;

	nums = find_nums_rows(board, j);
	if (valid_array(nums))
	{
		free(nums);
		return (1);
	}
	free(nums);
	return (0);
}

int	valid_cols_rows(char **board)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if ((valid_cols(board, i) || valid_rows(board, i)))
			return (1);
		i++;
	}
	return (0);
}

char	*get_nums(char **bd, int cr_x, int cr_y)
{
	char	*grid_nums;
	int		i;
	int		j;
	int		m;

	m = 0;
	grid_nums = malloc(10 * (sizeof(char)));
	if (!grid_nums)
		return (NULL);
	my_memset(grid_nums, 0, 10);
	grid_nums[9] = '\0';
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (bd[cr_x + i][cr_y + j] != '.' && bd[cr_x + i][cr_y + j] >= '0'
				&& bd[cr_x + i][cr_y + j] <= '9')
				grid_nums[m++] = bd[cr_x + i][cr_y + j];
			j++;
		}
		i++;
	}
	grid_nums[m] = '\0';
	return (grid_nums);
}

int	valid_3by3(char **board, int corner_x, int corner_y)
{
	char	*grid_nums;
	int		i;
	int		j;

	grid_nums = get_nums(board, corner_x, corner_y);
	i = 0;
	while ((i < 9) && (grid_nums[i] != '\0'))
	{
		j = i + 1;
		while ((i < 9) && (grid_nums[j] != '\0'))
		{
			if (grid_nums[i] == grid_nums[j])
			{
				free(grid_nums);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(grid_nums);
	return (0);
}

int	valid_grids(char **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (valid_3by3(board, 3 * i, 3 * j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	isValidSudoku(char **board, int boardSize, int *boardColSize)
{
	boardSize = 9;
	if (valid_cols_rows(board))
		return (false);
	else if (valid_grids(board))
		return (false);
	else
		return (true);
}

// int	main(void)
// {
// 	char *board[9] = {"5.....5..", "........9", "5.8......", "....6....",
// 		"......5..", "....4....", "...9......", "..5.......", "........4."};

// 	int boardSize = 9;
// 	int boardColSize[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

// 	if (isValidSudoku(board, boardSize, boardColSize))
// 		printf("Valid Sudoku (Rows & Cols only) ✅\n");
// 	else
// 		printf("Invalid Sudoku ❌\n");

// 	return (0);
// }