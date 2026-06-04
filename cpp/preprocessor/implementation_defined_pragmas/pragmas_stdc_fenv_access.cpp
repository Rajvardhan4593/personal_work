#include <iostream>
#include <cfenv>    // In your compiler settings, select cpp version > 11 to enable this library to be used
using namespace std;

#pragma STDC FENV_ACCESS ON // Tells the compiler to not directly give floating point errors/warnings, it will be controlled by me/user.

int main()
{
    feclearexcept(FE_ALL_EXCEPT);           // This is a built-in api
    double x = 1.0/0.0;                     // zero division
    if (fetestexcept(FE_DIVBYZERO)) {       // This is a built-in api that checks if before any floating point variable is divided by zero
        cout << "ZERO DIVISION DETECTED!";
    }
    return 0;
}
