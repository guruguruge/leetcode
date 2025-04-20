#include "ft.h"

bool	isPalindrome(char *s)
{
	int size = my_strlen(s);

	int i = 0;
	int k = 0;
	char *s1;
	s1 = my_calloc(size + 1, sizeof(char));
	while (s[i] != '\0')
	{
		if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))
			|| ((s[i] >= '0') && (s[i] <= '9')))
		{
			if (((s[i] >= 'A') && (s[i] <= 'Z')))
				s[i] += 'a' - 'A';

			s1[k] = s[i];
			k++;
		}

		i++;
	}
	s1[k] = '\0';

	size = k;

	i = 0;
	while (i < size / 2)
	{
		char temp;
		temp = s1[i];
		if (s1[i] != s1[size - i - 1])
		{
			free(s1);
			return (false);
		}
		i++;
	}

	free(s1);
	return (true);
}