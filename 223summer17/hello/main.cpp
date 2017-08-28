#include <iostream>

using namespace std;

class ABC
{
public:
	static void Function() { cout << "In function" << this->x << endl; }
};

int main(int argc, const char* argv[]}
{
	ABC a;
	a.Function();
	return 0;
}
