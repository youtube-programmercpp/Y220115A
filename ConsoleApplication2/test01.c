#include<stdio.h>
void func(int*, int*);
main()
{
	int a[3] = { 3, 4, 5 };
	int d[3] = { 4, 5, 6 };

	func(a, d);


	int i;
	for (i = 0; i < 3; i++) printf("a[%d] = %d\n", i, a[i]);
	for (i = 0; i < 3; i++) printf("d[%d] = %d\n", i, d[i]);
}
void func(int* p, int* q)
{
	int i;
	for (i = 0; i < 3; i++) {


		p[i] = p[i] + q[i];
		q[i] = p[i] - q[i];
		p[i] = p[i] - q[i];


	}
}
