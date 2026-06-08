/*
  #pragma STDC CX_LIMITED_RANGE ON/OFF:
    - This pragma is used when there is need of faster execution results for complex number math operations.
    - In case of complex number math, the values may overflow so there are floating point checks to avoid overflows.
    - This validation slows down the performance i.e time of execution increase.
    - If user knows that the values are smaller enough to produce required results then use this pragma.
    - The default value of this pragma is OFF.

  Basic complex number math: Complex Number Multiplication: (x + iy)(u + iv) = (xu - yv) + i(xv + yu)
*/

#include <iostream>
#include <complex>
using namespace std;

int main()
{
    complex<double> var1(2.0,3.0);
    complex<double> var2(4.0,5.0);
    complex<double> result = var1 * var2;

    cout << "Real = " << result.real() << endl;      // -7
    cout << "Imaginary = " << result.imag() << endl; // 22

    return 0;
}
