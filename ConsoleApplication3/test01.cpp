#include <string>
void f(std::string&& s)
{
	//std::string s2 = s;//�R�s�[����
	std::string s2 = std::move(s);//�R�s�[��������
}
int main()
{
	f("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
