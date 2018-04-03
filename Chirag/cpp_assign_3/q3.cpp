//Q3

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream out("global_edge");
	if(!out)
	{
		cout << "Cannot open the file\n";
		return 1;
	}

	out << "WELCOME TO GLOBAL EDGE\n";

	out.close();

	ifstream in("global_edge");
	if(!in) {
		cout << "Cannot open the file\n";
		return 1;
	}

	char item[20];

	in.getline(item, 255);
	cout << item << endl;

	in.close();

	return 0;
}	
