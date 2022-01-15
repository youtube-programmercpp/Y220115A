#include <atlstr.h>
void f(CStringA&& s)
{
	CStringA s2 = s;
	s2.SetAt(0, '*');
}

int main()
{
	f("XXXXXXXXXXXXXXXXXXXX");
}
