#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream out("global_edge");
	if(!out) {
		cout << "Cannot open file.\n";
		return 1;
	}

	out << "WELCOME TO GLOBALEDGE" << endl;

	out.close();

	ifstream in("global_edge");
	if(!in) {
		cout << "Cannot open file.\n";
		return 1;
	}
	char item[100];
	in.getline(item,100);
	cout << item;

	in.close();
	
	return 0;
}
