#include "ft.h"

typedef struct s_elem
{
	int			key;
	int			count;
}				t_elem;

typedef struct s_hash
{
	char *key;              // key
	unsigned int frequency; // frquency
	struct s_hash *next;    // chain
}				t_hash;

#define BUCKET 2003

unsigned int	hash_function(int num)
{
	return ((unsigned int)(num + 1000) % BUCKET);
}

t_hash	*create_node(int key)
{
	t_hash	*node;

	node = (t_hash *)malloc(sizeof(t_hash));
	if (!node)
		return (NULL);
	node->key = key;
	node->frequency = 1;
	node->next = NULL;
	return (node);
}

int	cmp(const void *a, const void *b)
{
	return (((t_elem *)b)->count - ((t_elem *)a)->count);
}

int	*topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
	int i = 0;

	t_hash *hash_table[BUCKET] = {NULL};

	while (i < numsSize)
	{
		int hash_key = hash_function(nums[i]);
		t_hash *node = hash_table[hash_key];
		while (node)
		{
			if (node->key == nums[i])
			{
				node->frequency++;
				break ;
			}
			node = node->next;
		}

		if (!node)
		{
			t_hash *new_node = create_node(nums[i]);
			new_node->next = hash_table[hash_key];
			hash_table[hash_key] = new_node;
		}

		i++;
	}

	t_elem *elements = malloc(numsSize * sizeof(t_elem));
	int elem_count = 0;

	for (int i = 0; i < BUCKET; i++)
	{
		t_hash *cur = hash_table[i];
		while (cur)
		{
			elements[elem_count].key = cur->key;
			elements[elem_count].count = cur->frequency;
			elem_count++;
			cur = cur->next;
		}
	}

	qsort(elements, elem_count, sizeof(t_elem), cmp);

	int *ans;
	ans = (int *)malloc((k) * (sizeof(int)));
	if (!ans)
		return (NULL);

	i = 0;
	while (i < k)
	{
		ans[i] = elements[i].key;
		i++;
	}

	*returnSize = k;
	free(elements);

	return (ans);
}