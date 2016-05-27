//这是我送给你们德圣诞节礼物
#include<stdio.h>
#include<Windows.h>

int main()
{
	int i, j, x, n = 0;
	char a = 32, b = 42, c = 48;
	for (x = 0; x<3; x++)
	{
		for (i = 0; i<x + 3; i++)
		{
			for (j = 0; j<80; j++)
			{
				if (j <= 25 + n&&j >= 25 - n)
					printf("%c", c);
				else if ((j % (n + 6) == n) && (j>25 + n || j<25 - n))
					printf("%c", b);
				else
					printf("%c", a);
			}
			printf("\n");
			n = n + 2;
		}
		n = n - 2 * (x + 2);
	}
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<80; j++)
		{
			if (j >= 22 && j <= 28)
				printf("%c", c);
			else if ((j % (n + 6) == n) && (j>25 + n || j<25 - n))
				printf("%c", b);
			else
				printf("%c", a);
		}
		n = n + 2;
		printf("\n");
	}
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<80; j++)
		{
			if (j % 2 == 0)
				printf("%c", b);
			else
				printf("%c", a);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}