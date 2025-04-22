#include "ft.h"

int	can_eat_all(int *piles, int pilesSize, int h, int k)
{
	int			i;
	long long	time;

	time = 0;
	i = 0;
	while (i < pilesSize)
	{
		time += (piles[i] + k - 1) / (k);
		i++;
	}
	if (time <= h)
		return (1);
	else
		return (0);
}

int	minEatingSpeed(int *piles, int pilesSize, int h)
{
	int max_piles = 1;
	int i = 0;
	while (i < pilesSize)
	{
		if (max_piles < piles[i])
			max_piles = piles[i];
		i++;
	}

	int k_left = 1;
	int k_right = max_piles;
	int result = max_piles;

	while (k_left <= k_right)
	{
		int k = (k_left + k_right) / 2;

		if (can_eat_all(piles, pilesSize, h, k))
		{
			result = k;
			k_right = k - 1;
		}
		else
		{
			k_left = k + 1;
		}
	}
	return (result);
}