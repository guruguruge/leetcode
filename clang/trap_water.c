#include "ft.h"

int	sum_area(int *height, int left, int right)
{
	int	l_h;
	int	r_h;
	int	i;
	int	area;

	i = left + 1;
	area = 0;
	l_h = height[left];
	r_h = height[right];
	if (l_h <= r_h)
	{
		while (i < right)
		{
			area += l_h - height[i];
			i++;
		}
	}
	else
	{
		while (i < right)
		{
			area += r_h - height[i];
			i++;
		}
	}
	return (area);
}

int	trapWater(int *height, int heightSize)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	i = 0;
	while (i < heightSize)
	{
		j = 0;
		while ((i + j < heightSize) && (height[i] > 0))
		{
			j++;
			if (height[i + j] >= height[i])
				result += sum_area(height, i, j);
		}
		i = i + j;
		i++;
	}
	return (result);
}
