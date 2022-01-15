//C++‚Å‚ÍŽg‚¦‚Ü‚¹‚ñ
//C99‚©‚çŽg‚¦‚Ü‚·

// compound literal
#include <stdio.h>

int main()
{
#if 1
	int* p = (int[5]) {100, 200, 300, 400, -1};
#else
	int a[] = { 100, 200, 300, 400, -1 };
	int* p = a;
#endif
	for (;*p != -1;++p)
		printf("%d\n", *p);
}
