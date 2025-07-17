#include "ft.h"

bool	searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
		int target)
{
	int	i;
	int	mid;
	int	left;
	int	right;

	i = 0;
	while (i < matrixSize)
	{
		left = 0;
		right = matrixColSize[i] - 1;
		while (left <= right)
		{
			mid = (right + left) / 2;
			if ((target == matrix[i][mid]))
				return (true);
			else if (matrix[i][mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		i++;
	}
	return (false);
}
