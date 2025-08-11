#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	make_array(int size, int *res, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		res[i] = atoi(av[j + 1]);
		i++;
		j++;
	}
}

int	get_sum(int *res, int size)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += res[i];
		i++;
	}
	return (sum);
}

void	print_nums(int *res, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("%d", res[i]);
		else
			printf(" %d", res[i]);
		i++;
	}
	printf("\n");
}

void	generate(int target, int size, int *res, int *array, int dep,
		int sub_size)
{
	int	sum;

	if (dep == size)
	{
		sum = get_sum(res, sub_size);
		if (sum == target)
		{
			print_nums(res, sub_size);
		}
		return ;
	}
	generate(target, size, res, array, dep + 1, sub_size);
	res[sub_size] = array[dep];
	generate(target, size, res, array, dep + 1, sub_size + 1);
}

int	main(int ac, char **av)
{
	int	target;
	int	size;
	int	*res;
	int	*nums;

	if (ac > 2)
	{
		if (ac == 2)
		{
			printf("\n");
			return (0);
		}
		else
		{
			target = atoi(av[1]);
			size = ac - 2;
			nums = malloc(size * sizeof(int));
			if (!nums)
				return (1);
			make_array(size, nums, av);
			res = malloc(size * sizeof(int));
			if (!res)
				return (free(nums), 1);
			generate(target, size, res, nums, 0, 0);
			free(nums);
			free(res);
			return (0);
		}
	}
	else
		return (0);
}
