#include <misc/string.h>
#include <misc/stlutil.h>

#define SHOW(x) #x"= " << (x)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
	// fromHex4

	cout << SHOW(fromHex4('0')) << endl;
	cout << SHOW(fromHex4('1')) << endl;
	cout << SHOW(fromHex4('2')) << endl;
	cout << SHOW(fromHex4('3')) << endl;
	cout << SHOW(fromHex4('4')) << endl;
	cout << SHOW(fromHex4('5')) << endl;
	cout << SHOW(fromHex4('6')) << endl;
	cout << SHOW(fromHex4('7')) << endl;
	cout << SHOW(fromHex4('8')) << endl;
	cout << SHOW(fromHex4('9')) << endl;
	cout << SHOW(fromHex4('a')) << endl;
	cout << SHOW(fromHex4('A')) << endl;
	cout << SHOW(fromHex4('b')) << endl;
	cout << SHOW(fromHex4('B')) << endl;
	cout << SHOW(fromHex4('c')) << endl;
	cout << SHOW(fromHex4('C')) << endl;
	cout << SHOW(fromHex4('d')) << endl;
	cout << SHOW(fromHex4('D')) << endl;
	cout << SHOW(fromHex4('e')) << endl;
	cout << SHOW(fromHex4('E')) << endl;
	cout << SHOW(fromHex4('f')) << endl;
	cout << SHOW(fromHex4('F')) << endl;

	// toHex4

	cout << SHOW(toHex4( 0)) << endl;
	cout << SHOW(toHex4( 1)) << endl;
	cout << SHOW(toHex4( 2)) << endl;
	cout << SHOW(toHex4( 3)) << endl;
	cout << SHOW(toHex4( 4)) << endl;
	cout << SHOW(toHex4( 5)) << endl;
	cout << SHOW(toHex4( 6)) << endl;
	cout << SHOW(toHex4( 7)) << endl;
	cout << SHOW(toHex4( 8)) << endl;
	cout << SHOW(toHex4( 9)) << endl;
	cout << SHOW(toHex4(10)) << endl;
	cout << SHOW(toHex4(11)) << endl;
	cout << SHOW(toHex4(12)) << endl;
	cout << SHOW(toHex4(13)) << endl;
	cout << SHOW(toHex4(14)) << endl;
	cout << SHOW(toHex4(15)) << endl;

	// ato*

	cout << SHOW(atof("   0.001")) << endl;
	cout << SHOW(atof("  -0.001")) << endl;
	cout << SHOW(atof(" 100.001")) << endl;
	cout << SHOW(atof("-100.001")) << endl;
	cout << SHOW(atof("    1e10")) << endl;
	cout << SHOW(atof("   1e-10")) << endl;

	cout << SHOW(atoi("-123456")) << endl;
	cout << SHOW(atoi("      0")) << endl;
	cout << SHOW(atoi(" 123456")) << endl;

	cout << SHOW(atol("-1234567890")) << endl;
	cout << SHOW(atol("+1234567890")) << endl;

	cout << SHOW(atob("false")) << endl;
	cout << SHOW(atob("true")) << endl;
	cout << SHOW(atob("0")) << endl;
	cout << SHOW(atob("1")) << endl;
	cout << SHOW(atob("-1")) << endl;

	// atoc

	{
		vector<int> tmp(5);
	
		cout << SHOW(atoc("1,2,3,4,5",atoi,"+-0123456789",tmp.begin(),tmp.end())) << endl;
		print(cout,tmp) << endl;
	
		cout << SHOW(atoc("+1,-2,+3,-4,+5",atoi,"+-0123456789",tmp.begin(),tmp.end())) << endl;
		print(cout,tmp) << endl;
	}

	{
		vector<bool> tmp(5);

		cout << SHOW(atoc("true false 1 0 -1",atob,"+-01truefalse",tmp.begin(),tmp.end())) << endl;
		print(cout,tmp) << endl;
	}

	// split
	
	{
		vector<string> tmp;

		cout << SHOW(stringSplit(tmp,"One Two Three Four Five"," ")) << endl;
		print(cout,tmp) << endl;

		string tmp2;
		cout << SHOW(stringMerge(tmp,tmp2," ")) << endl;
		cout << tmp2 << endl;
	}

	// bin2src

	unsigned char buffer[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bin2src(cout,buffer,10);

	bin2src(cout,"0123456789abcde");

	return EXIT_SUCCESS;
}

