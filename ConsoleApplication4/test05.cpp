struct sample {
	int a;
	int b;
};
#include <stdio.h>
void f_cpp(const sample& r)
{
	printf("%d, %d\n", r.a, r.b);
}
void f_c(const sample* p)
{
	printf("%d, %d\n", p->a, p->b);
}
int main()
{
	const sample x{ 123, 456 };
	f_c(&x);
	f_cpp({ 123, 456 });
}
