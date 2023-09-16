#include <stdio.h>

int main()
{
	
	int sum = 0;
	int i = 2;
	int j;
	int cnt = 0;

	while (i < 101)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				cnt += 1;
				break;
			}
		}
		if (cnt == 0)
		{
			sum += i;
		}
		cnt = 0;
		i++;
	}
	printf("%d", sum);
}
