#include <stdio.h>
int main()
{
	int* p;
	int** pw;

	int n = 2, m = 7;

	p = &n;
	pw = &p;
	p = &m;
	printf("%d %d\n", m, m);
}
