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
