#include <string>
void f(std::string&& s)
{
	//std::string s2 = s;//コピー発生
	std::string s2 = std::move(s);//コピー発生せず
}
int main()
{
	f("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
