#include <iostream>

using namespace std;

int a[1005];

int main()
{
	for (int i = 1; i <= 10; i++) scanf("%d", &a[i]);
	printf("\n");
	for (int i = 1; i <= 10; i++) printf("%d ", a[i]);
	return 0;
}