#include "header.h"

int main(void)
{
	char indata[] = "WELCOME TO GLOBALEDGE";
	char outdata[(sizeof(indata)/sizeof(indata[0]))];

	ofstream out;

	out.open("sample.txt");

	out << indata;

	out.close();

	ifstream in;

	in.open("sample.txt");
	
	while(!(in.eof())){
		in >> outdata;
		cout << outdata << endl;
	}

	return EXIT_SUCCESS;
}
