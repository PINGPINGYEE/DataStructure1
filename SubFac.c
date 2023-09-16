#include <stdio.h>

double factorial_iter(int n)
{
	double res = 1;
	int i;
	for (i = n; i > 0; i--)
	{
		res = res * i;
	}
	return res;
}


double factorial_rec(int n)
{

	if (n <= 1)
	{
		return 1;
	}
	return n * factorial_rec(n - 1);
}

int main()
{

	int n = 20;
	double result_iter = factorial_iter(n);
	double result_rec = factorial_rec(n);
	printf("Iterative factorial result: %.0f\n", result_iter);
	printf("Recursive factorial result: %.0f\n", result_rec);
}