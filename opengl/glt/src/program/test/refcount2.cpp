#include <misc/refcount.h>

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[])
{
	ReferenceCountPtr<int> ptr = new int;

	// Access the dynamically allocated
	// integer

	*ptr = 12345;

	//

	cout << *ptr << endl;
	cout << *(ptr.get()) << endl;

	return EXIT_SUCCESS;
}
