#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	*gen_nums(int size, char **in)
{
	int	i;
	int	j;
	int	*res;

	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	j = 2;
	while (i < size)
	{
		res[i] = atoi(in[j]);
		i++;
		j++;
	}
	return (res);
}

int	get_sum(int *nums, int size)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += nums[i];
		i++;
	}
	return (sum);
}

void	print_nums(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("%d", nums[i]);
		else
			printf(" %d", nums[i]);
		i++;
	}
	printf("\n");
}

void	generate(int *nums, int *out, int size, int target, bool *used, int dep,
		int outlen)
{
	int	sum;

	sum = 0;
	if (dep == size)
	{
		sum = get_sum(out, outlen);
		if (sum == target)
		{
			print_nums(out, outlen);
		}
		return ;
	}
	generate(nums, out, size, target, used, dep + 1, outlen);
	out[outlen] = nums[dep];
	generate(nums, out, size, target, used, dep + 1, outlen + 1);
}

int	main(int ac, char **av)
{
	int		target;
	int		size;
	int		*nums;
	int		*out;
	bool	*used;

	if (ac > 1)
	{
		target = atoi(av[1]);
		if (ac == 2)
		{
			if (target == 0)
			{
				printf("\n");
				return (0);
			}
			else
				return (0);
		}
		size = ac - 2;
		nums = gen_nums(size, av);
		if (!nums)
			return (EXIT_FAILURE);
		// print_nums(nums, size);`
		out = calloc(size, sizeof(int));
		if (!out)
			return (free(nums), EXIT_FAILURE);
		used = calloc(size, sizeof(int));
		if (!used)
			return (free(nums), free(out), EXIT_FAILURE);
		generate(nums, out, size, target, used, 0, 0);
		free(nums);
		free(out);
		return (0);
	}
	else
		return (0);
}
