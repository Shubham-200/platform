#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangle
{
	private:
		float length;
		float width;
		float totalPerimeter;
		float totalArea;

	public:
		void setLength(float len){
			this -> length = len;
		}

		void setWidth(float wid){
			this -> width = wid;
		}

		float perimeter(void){
			this -> totalPerimeter = this -> length + this -> width;

			return this -> totalPerimeter;
		}
	
		float area(void){
			this -> totalArea = this -> length * this -> width;

			return this -> totalArea;
		}

		void show(void){
			cout << "total area = " << this -> area() << endl;
			cout << "total perimeter = " << this -> perimeter() << endl;
		}		

		int sameArea(Rectangle rect){
			
			if(this -> totalArea == rect.totalArea)
				return 1;

			return 0;
		}
};
