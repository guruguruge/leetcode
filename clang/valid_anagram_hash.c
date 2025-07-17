#include "ft.h"

#define ALPHABET 26

int	valid_anagram_hash(char *s1, char *s2)
{
	int	i;
	int	hash1[ALPHABET] = {0};
	int	hash2[ALPHABET] = {0};

	if ((my_strlen(s1) != my_strlen(s2)))
	{
		printf("false");
		return (0);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		hash1[s1[i] - 'a']++;
		hash2[s2[i] - 'a']++;
		i++;
	}
	i = 0;
	while (i < ALPHABET)
	{
		if (hash1[i] != hash2[i])
		{
			printf("false");
			return (0);
		}
		i++;
	}
	printf("true");
	return (1);
}

// int	main(void)
// {
// 	char *s1 = "aww";
// 	char *s2 = "aww";
// 	return (valid_anagram_hash(s1, s2));
// }