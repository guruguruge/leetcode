#include "ft.h"

int	my_atoi(char num[])
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((num[i] == ' ') || (num[i] >= '\t' && num[i] <= '\r'))
		i++;
	while ((num[i] == '+') || (num[i] == '-'))
	{
		if ((num[i] == '-'))
			sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + (num[i] - '0');
		i++;
	}
	return (sign * result);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	my_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] != '\0') && (str2[i] != '\0') && (str1[i] == str2[i]))
	{
		i++;
	}
	return ((unsigned int)str1[i] - (unsigned int)str2[i]);
}

void	my_strswp(char *str1, char *str2)
{
	char	temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	*my_memset(void *str, int c, size_t n)
{
	unsigned char	*str_c;
	unsigned char	char_c;
	size_t			i;

	char_c = (unsigned char)c;
	str_c = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		str_c[i] = char_c;
		i++;
	}
	return (str);
}

void	*my_calloc(size_t element_num, size_t size)
{
	void	*str;

	str = malloc(element_num * size);
	if (!str)
		return (NULL);
	my_memset(str, 0, element_num * size);
	return (str);
}

int	str_partition(char arr[], int low, int high)
{
	char	pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			my_strswp(&arr[i], &arr[j]);
		}
		j++;
	}
	my_strswp(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort_str(char arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = str_partition(arr, low, high);
		quicksort_str(arr, low, pi - 1);
		quicksort_str(arr, pi + 1, high);
	}
}

void	my_strsort(char *str)
{
	int size = my_strlen(str);
	quicksort_str(str, 0, size - 1);
}