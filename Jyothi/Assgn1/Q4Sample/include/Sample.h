#include <iostream>
#include <stdlib.h>

using namespace std;

class Sample
{
	private:
    	int x;
    	double y;
	
	public :
   		Sample(){ //Constructor 1
			x = 0;
			y = 0;
		}

    	Sample(int x){ //Constructor 2
			this -> x = x;
			y = 0;
		}

    	Sample(int x, int y){ //Constructor 3
			this -> x = x;
			this -> y = y;	
		}

    	Sample(int x, double y){ //Constructor 4
			this -> x = x;
			this -> y = y;	
		}

		void myPrint(void){
            cout << "x: " << x << endl;
            cout << "y: " << y << endl;
        }

};
