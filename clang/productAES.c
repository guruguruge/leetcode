#include <string.h>

int	*productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int *res = calloc(sizeof(int), (numsSize));
	if (!res)
		return (NULL);

	int i = 1;
	res[0] = 1;
	while (i < numsSize)
	{
		res[i] = res[i - 1] * nums[i - 1];
		i++;
	}
	i = numsSize - 1;
	int right = 1;
	while (i >= 0)
	{
		res[i] *= right;
		right *= nums[i];
		i--;
	}
	*returnSize = numsSize;
	return (res);
}