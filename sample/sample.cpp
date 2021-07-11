#include "ls/io/Factory.h"
#include "iostream"

using namespace std;
using namespace ls;

int main()
{
	Buffer *buffer = new Buffer();
	buffer -> push("12345678");
	auto in = io::factory.makeInputStream(nullptr, buffer);
	auto text = in -> split(5);
	cout << text << endl;
	delete in;
	return 0;
}
