#include "class.h"

void base :: show()
{
    cout << "Base class : virtual show() function" << endl;
}

void base :: display()
{
    cout << "Base class : virtual display() function" << endl;
}

void derived :: show()
{
    cout << "Derived class : show() function" << endl;
}

void derived :: display()
{
    cout << "Derived class : display() function" << endl;
}
            
