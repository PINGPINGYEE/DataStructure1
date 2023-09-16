#define MAX_DEGREE 101
#include <stdio.h>
#include <windows.h>

struct pn;
typedef struct
{
	int degree;
	float coef[MAX_DEGREE];
} pn;


pn pn_mul(pn a, pn b);

void print_p(pn p);


int main(void)
{
	printf("결과 확인 조건 1\n");
	pn a1 = { 3, {4, 3, 2, 1} };
	pn b1 = { 2, {3, 2, 8} };
	pn d;
	print_p(a1);
	print_p(b1);
	d = pn_mul(a1, b1);
	print_p(d);
	printf("결과 확인 조건 2\n");
	pn a2 = { 6, {7, 0, 0, 5, 9, 0, 1} };
	pn b2 = { 3, {5, 2, 1, 10} };
	print_p(a2);
	print_p(b2);
	d = pn_mul(a2, b2);
	print_p(d);
	system("pause");

	return(0);
}


pn pn_mul(pn a, pn b)
{
	pn d;
	int i, j, k;

	d.degree = a.degree + b.degree;

	for (k = 0; k <= d.degree; k++)
	{
		d.coef[k] = 0;
	}

	for (i = 0; i <= a.degree; i++)
	{
		for (j = 0; j <= b.degree; j++)
		{
			d.coef[i + j] += a.coef[i] * b.coef[j];
		}
	}

	return d;
}


void print_p(pn p)
{
	for (int i = p.degree; i > 0; i--)
	{
		printf(" % 3.0fx^%d + ", p.coef[p.degree - i], i);
	}
	printf(" % 3.0f\n", p.coef[p.degree]);
}
