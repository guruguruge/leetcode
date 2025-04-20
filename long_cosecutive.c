#include "ft.h"

#define OFFSET 1000000000
#define BUCKET 10007

typedef struct s_hash
{
	int				key;
	unsigned int	value;
	struct s_hash	*next;
}					t_hash;

unsigned int	hash_function(int num)
{
	unsigned long long	temp;

	temp = (unsigned long long)num + OFFSET;
	return (unsigned int)(temp % BUCKET);
}

t_hash	*create_node(int key)
{
	t_hash	*node;

	node = (t_hash *)malloc(sizeof(t_hash));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = 1;
	node->next = NULL;
	return (node);
}

int	exists(t_hash **hash_table, int num)
{
	unsigned int	key;
	t_hash			*node;

	key = hash_function(num);
	if (key >= BUCKET)
		return (0);
	node = hash_table[key];
	while (node)
	{
		if (node->key == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	longestConsecutive(int *nums, int numsSize)
{
	int i = 0;

	t_hash *hash_table[BUCKET] = {NULL};

	while (i < numsSize)
	{
		int key = hash_function(nums[i]);
		t_hash *node = hash_table[key];
		while (node)
		{
			if (node->key == nums[i])
				break ;

			node = node->next;
		}

		if (!node)
		{
			t_hash *new_node = create_node(nums[i]);
			new_node->next = hash_table[key];
			hash_table[key] = new_node;
		}

		i++;
	}

	int max_length = 0;
	i = 0;
	while (i < numsSize)
	{
		int num = nums[i];
		if (!exists(hash_table, num - 1))
		{
			int current = num;
			int conseq = 1;
			while (exists(hash_table, current + 1))
			{
				current++;
				conseq++;
			}
			if (conseq > max_length)
				max_length = conseq;
		}
		i++;
	}

	return (max_length);
}