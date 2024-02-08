#include <iostream>
#include <time>

using namespace std;

int main()
{
	freopen("text.in", "w", stdout);
	printf("2000\n");
	for (int i = 1; i <= 2000; i++)
	{
		for (int j = 1 ; j <= 2000; j++)
		{
			printf("%d ", rand() % 2);
		}
		printf("\n");
	}
	return 0;
}
