#include "ft.h"

int	*productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int	*ans;
	int	i;
	int	right;

	ans = (int *)my_calloc(sizeof(int), numsSize);
	if (!ans)
		return (NULL);
	i = 1;
	ans[0] = 1;
	while (i < numsSize)
	{
		ans[i] = nums[i - 1] * ans[i - 1];
		i++;
	}
	i = numsSize - 1;
	right = 1;
	while (i >= 0)
	{
		ans[i] *= right;
		right *= nums[i];
		i--;
	}
	*returnSize = numsSize;
	return (ans);
}

int	main(void)
{
	int nums[3] = {1, 2, 3};
	int return_s;
	int *result = productExceptSelf(nums, 3, &return_s);

	int i = 0;
	while (i < return_s)
	{
		printf("%d\n", result[i]);
		i++;
	}

	free(result);

	return (0);
}