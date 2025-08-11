#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *array, int size);

int	*make_array(char **av, int size)
{
	int	i;
	int	*res;
	int	j;

	res = malloc((size) * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	j = 2;
	while (i < size)
	{
		res[i] = atoi(av[j]);
		j++;
		i++;
	}
	return (res);
}

int	get_sum(int *array, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		res += array[i];
		i++;
	}
	return (res);
}

void	print_subset(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("%d", array[i]);
		else
			printf(" %d", array[i]);
		i++;
	}
	printf("\n");
}

void	generate(int *nums, int *subset, int target, int i, int size,
		int sub_size)
{
	int	sum;

	if (i == size)
	{
		sum = get_sum(subset, sub_size);
		if (sum == target)
			print_subset(subset, sub_size);
		return ;
	}
	generate(nums, subset, target, i + 1, size, sub_size);
	subset[sub_size] = nums[i];
	generate(nums, subset, target, i + 1, size, sub_size + 1);
}

int	main(int ac, char **av)
{
	int target;
	int *nums;
	int *subset;
	int size;

	if (ac >= 2)
	{
		target = atoi(av[1]);
		size = ac - 2;
		if (ac == 2)
		{
			if (target == 0)
				printf("\n");
			return (0);
		}
		else
		{
			nums = make_array(av, size);
			subset = calloc(size, sizeof(int));
			if (!subset)
				return (free(nums), 1);
			generate(nums, subset, target, 0, size, 0);
			free(subset);
			free(nums);
			return (0);
		}
	}
	return (0);
}