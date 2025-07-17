#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10007 // 適度な素数でバケツ数を確保

// t_map構造体
typedef struct s_map
{
	char *key;          // ソートされた文字列
	int index;          // group配列内のindex
	struct s_map *next; // 衝突解決用（チェイン法）
}				t_map;

// t_group構造体
typedef struct s_group
{
	char *key;    // ソートされた文字列（グループの識別子）
	char **words; // 同じキーの元文字列の配列
	int count;    // 現在の個数
	int capacity; // wordsの容量
}				t_group;

// ハッシュ関数（簡単な文字列のハッシュ）
unsigned int	hash(const char *key)
{
	unsigned int	h;

	h = 0;
	while (*key)
	{
		h = (h * 31) + (*key++);
	}
	return (h);
}

// t_mapを作成する関数
t_map	*create_map(const char *key, int index)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->key = strdup(key); // keyを複製
	new_map->index = index;
	new_map->next = NULL;
	return (new_map);
}

// ハッシュテーブルにマップを挿入
void	map_insert(t_map **table, const char *key, int index)
{
	unsigned int	h;
	t_map			*entry;
	t_map			*new_map;

	h = hash(key) % TABLE_SIZE;
	entry = table[h];
	// 衝突があれば、リストに追加
	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			return ; // すでに同じキーがあれば何もしない
		}
		entry = entry->next;
	}
	// 新たにマップを挿入
	new_map = create_map(key, index);
	new_map->next = table[h];
	table[h] = new_map;
}

// アナグラムのグループを作成
t_group	*create_group(const char *key)
{
	t_group	*group;

	group = (t_group *)malloc(sizeof(t_group));
	group->key = strdup(key);
	group->words = (char **)malloc(sizeof(char *) * 10);
	group->count = 0;
	group->capacity = 10;
	return (group);
}

// ハッシュテーブルからインデックスを取得
int	map_get_index(t_map **table, const char *key)
{
	unsigned int	h;
	t_map			*entry;

	h = hash(key) % TABLE_SIZE;
	entry = table[h];
	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
			return (entry->index);
		entry = entry->next;
	}
	return (-1);
}

// グループをアナグラムのリストに格納
void	add_word_to_group(t_group **groups, int group_index, const char *word)
{
	if (groups[group_index]->count == groups[group_index]->capacity)
	{
		groups[group_index]->capacity *= 2;
		groups[group_index]->words = (char **)realloc(groups[group_index]->words,
				sizeof(char *) * groups[group_index]->capacity);
	}
	groups[group_index]->words[groups[group_index]->count] = strdup(word);
	groups[group_index]->count++;
}

// アナグラムグループを作成
char	***group_anagrams(char **strs, int strs_size, int *return_size,
		int **return_column_sizes)
{
	int		group_count;
	char	*sorted_word;
	int		group_index;
	char	***result;
	t_map	*table[TABLE_SIZE] = {0};
	t_group	**groups;

	// ハッシュテーブルの初期化
	groups = (t_group **)malloc(sizeof(t_group *) * strs_size);
	// グループ配列の初期化
	group_count = 0;
	// 各単語をソートしてアナグラムグループを作成
	for (int i = 0; i < strs_size; i++)
	{
		sorted_word = strdup(strs[i]);
		// 文字列をソート
		qsort(sorted_word, strlen(sorted_word), sizeof(char),
			(int (*)(const void *, const void *))strcmp);
		// すでにソートされた文字列がテーブルに存在するか確認
		group_index = map_get_index(table, sorted_word);
		if (group_index == -1)
		{
			// 新しいグループを作成
			group_index = group_count++;
			groups[group_index] = create_group(sorted_word);
			map_insert(table, sorted_word, group_index);
		}
		// 現在のグループに単語を追加
		add_word_to_group(groups, group_index, strs[i]);
		free(sorted_word);
	}
	// 結果の構造体を返す
	*return_size = group_count;
	*return_column_sizes = (int *)malloc(sizeof(int) * group_count);
	result = (char ***)malloc(sizeof(char **) * group_count);
	for (int i = 0; i < group_count; i++)
	{
		(*return_column_sizes)[i] = groups[i]->count;
		result[i] = groups[i]->words;
		free(groups[i]->key);
		free(groups[i]);
	}
	return (result);
}

void	print_result(char ***result, int return_size, int *return_column_sizes)
{
	for (int i = 0; i < return_size; i++)
	{
		printf("[ ");
		for (int j = 0; j < return_column_sizes[i]; j++)
		{
			printf("\"%s\" ", result[i][j]);
		}
		printf("]\n");
	}
}

int	main(void)
{
	// テストケース1
	char *strs1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	int return_size1 = 0;
	int *return_column_sizes1 = NULL;
	char ***result1 = group_anagrams(strs1, 6, &return_size1,
			&return_column_sizes1);
	printf("Test Case 1:\n");
	print_result(result1, return_size1, return_column_sizes1);
	free(return_column_sizes1);
	free(result1);

	// テストケース2
	char *strs2[] = {"", "a", "b", ""};
	int return_size2 = 0;
	int *return_column_sizes2 = NULL;
	char ***result2 = group_anagrams(strs2, 4, &return_size2,
			&return_column_sizes2);
	printf("\nTest Case 2:\n");
	print_result(result2, return_size2, return_column_sizes2);
	free(return_column_sizes2);
	free(result2);

	// テストケース3
	char *strs3[] = {"z", "a", "b", "z", "a"};
	int return_size3 = 0;
	int *return_column_sizes3 = NULL;
	char ***result3 = group_anagrams(strs3, 5, &return_size3,
			&return_column_sizes3);
	printf("\nTest Case 3:\n");
	print_result(result3, return_size3, return_column_sizes3);
	free(return_column_sizes3);
	free(result3);

	// テストケース4
	char *strs4[] = {"apple", "apple", "apple"};
	int return_size4 = 0;
	int *return_column_sizes4 = NULL;
	char ***result4 = group_anagrams(strs4, 3, &return_size4,
			&return_column_sizes4);
	printf("\nTest Case 4:\n");
	print_result(result4, return_size4, return_column_sizes4);
	free(return_column_sizes4);
	free(result4);

	// テストケース5
	char *strs5[] = {"dog", "cat", "bat", "god", "tab", "act"};
	int return_size5 = 0;
	int *return_column_sizes5 = NULL;
	char ***result5 = group_anagrams(strs5, 6, &return_size5,
			&return_column_sizes5);
	printf("\nTest Case 5:\n");
	print_result(result5, return_size5, return_column_sizes5);
	free(return_column_sizes5);
	free(result5);

	return (0);
}