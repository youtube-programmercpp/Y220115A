struct sample {
	int a;
	int b;
};
#include <stdio.h>
void f(const struct sample* p)
{
	printf("%d, %d\n", p->a, p->b);
}
int main()
{
	f(&(struct sample){ 123, 456 });
}
