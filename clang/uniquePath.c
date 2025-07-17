// int	getFactorial(int n)
// {
// 	if (n == 0)
// 		return (1);
// 	else
// 		return (n * getFactorial(n - 1));
// }

// int	uniquePaths(int m, int n)
// {
// 	int mFactorial;
// 	int nFactorial;
// 	int mnFactorial;
// 	mFactorial = getFactorial(m);
// 	nFactorial = getFactorial(n);
// 	mnFactorial = getFactorial(m + n);
// 	return (mnFactorial / (mFactorial * nFactorial));
// }

int	uniquePaths(int m, int n)
{
	long whole = (long)(m + n - 2);
	long smaller = (long)(m <= n ? m - 1 : n - 1);
	long i = 0;
	long result = 1;

	while (i < smaller)
	{
		result = (whole - smaller + i);
		result /= i;
		i++;
	}
	return ((int)(result));
}