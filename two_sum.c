#include "ft.h"

#define NUMBER 20000000
#define OFFSET 10000000

int	*two_sum(int *nums, int num_size, int target, int *return_size)
{
	int	*num_hash;
	int	i;
	int	ans;
	int	*result;

	num_hash = my_calloc(NUMBER, sizeof(int));
	if (!num_hash)
		return (NULL);
	i = 0;
	while (i < num_size)
	{
		ans = target - nums[i];
		if (num_hash[ans + OFFSET] != 0)
		{
			result = (int *)malloc(2 * sizeof(int));
			if (!result)
				return (NULL);
			result[0] = num_hash[ans + OFFSET] - 1;
			result[1] = i;
			*return_size = 2;
			free(num_hash);
			return (result);
		}
		num_hash[nums[i] + OFFSET] = i + 1;
		i++;
	}
	*return_size = 0;
	free(num_hash);
	return (NULL);
}

int	main(void)
{
	int num_size = 3;
	int nums[] = {1, 150, 150};
	int target = 300;
	int return_size = 0;

	int *result = two_sum(nums, num_size, target, &return_size);
	if (return_size == 2)
	{
		printf("Indexes: %d, %d\n", result[0], result[1]);
		free(result);
	}
	else
	{
		printf("No two sum solution found.\n");
	}
	return (0);
}