
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	char item[100];

	ofstream out("Global edge");
	
	if(!out) {
		cout << "Cannot open Global edge \n";
		return 1;
	}
	
	out << "WELCOME TO GLOBAL EDGE" << endl;
	cout << "write complete" << endl;
	
	out.close();
	
	ifstream in("Global edge");
	
	if(!in) {
		cout << "cannot open file Global edge" << endl;
		return 1;
	}
	cout << "Reading the file" << endl;
	
//	in >> item ;
	in.getline(item, 100);
	cout << "Content of the file :" << endl;
	cout << item << endl;	
	in.close();		

	return 0;
}
