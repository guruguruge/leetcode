#include "ft.h"

int	valid_anagram(char *s1, char *s2)
{
	int	size1;

	size1 = my_strlen(s1);
	if ((size1 != my_strlen(s2)))
		return (1);
	my_strsort(s1);
	my_strsort(s2);
	if (my_strcmp(s1, s2) != 0)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char *s1 = "awevew";
// 	char *s2 = "erbipw";
// 	return (valid_anagram(s1, s2));
// }