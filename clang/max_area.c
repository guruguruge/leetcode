#include "ft.h"

int	length(int num1, int num2)
{
	if (num1 <= num2)
		return (num1);
	else
		return (num2);
}

int	maxArea(int *height, int heightSize)
{
	int left = 0;
	int right = heightSize - 1;

	int area = (right - left) * (length(height[right], height[left]));
	int i = 0;
	while (left < right)
	{
		if (height[left] <= height[right])
		{
			left++;
		}
		else
		{
			right--;
		}

		int temp_area = (right - left) * (length(height[right], height[left]));

		if (area <= temp_area)
		{
			area = temp_area;
		}
	}

	return (area);
}